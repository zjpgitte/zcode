#pragma once

#include "Sock.hpp"
#include "Log.hpp"

#define WEBROOT "./wwwroot"
#define HOMEPAGE "index.html"

class Request{
  public:
    Request(){}

    ~Request(){}

    void SetMethod(std::string s) {
      _method = move(s);
    }

    std::string& GetMethod() {
      return _method;
    }

    void SetUri(std::string s) {
      _uri = move(s);
    }

    std::string& GetUri() {
      return _uri;
    }

    void SetVersion(std::string s) {
      _version = move(s);
    }

    void Print() {
        std::cout << _method << " " << _uri << " " << _version << std::endl;
        for (auto& e : _headMap) {
          std::cout << e.first << ": " << e.second << std::endl;
        }
        std::cout << std::endl;

        std::cout << _body << std::endl;
    }

    void InsertToKVMap(std::string&& key, std::string&& val) {
        _headMap.insert(make_pair(std::forward<std::string>(key), std::forward<std::string>(val))); 
    }

    void PrintMap() {
      for (auto& e : _headMap) {
        std::cout << e.first << ": " << e.second << std::endl;
      }
    }

    void SetBody(std::string&& s) {
      _body = std::forward<std::string>(s); 
    }

    int GetContentLength() {
        return _contentLength;
    }
    void SetContentLength(int len) {
        _contentLength = len;    
    }

    void SetPath(std::string&& s) {
        _queryPath = std::forward<std::string>(s);
    }

    std::string& GetQueryPath() {
      return _queryPath;
    }

    void SetQueryParameter(std::string&& s) {
        _queryParameter = std::forward<std::string>(s);
    }

    std::string& GetQueryParameter() {
        return _queryParameter;
    }

    bool IsGet() {
        return !strcasecmp(_method.c_str(), "GET");
    }

    bool IsPost() {
        return !strcasecmp(_method.c_str(), "POST");
    }

    bool IsAddHomePage(std::string& queryPath) {
      if (queryPath.back() == '/') {
          queryPath += HOMEPAGE;
          return true;
      } 
      return false;
    }

    void GetQueryPathAndStringFromUri(std::string& queryPath, std::string queryParameter) {
      if (IsGet()) {
          //从uri获得path和参数
          size_t pos = _uri.find('?'); 
          if (pos == std::string::npos) { // 无参数
              _queryPath += _uri;
          }
          else { // 有参数
              _queryPath += std::string(_uri.begin(), _uri.begin() + pos); // ? 之前
              _queryParameter = std::string(_uri.begin() + pos + 1, _uri.end()); // ? 之后
          }
          
      }
      else if (IsPost()) {
          // 从uri获取路径
          // 从body获取参数
          _queryPath += _uri;

      }
      else {
        assert(false);
      }
      //若路径以/结尾需要添加 index.html
      IsAddHomePage(_queryPath);
      queryPath = _queryPath;
      queryParameter = _queryParameter;
    }
  private:
    std::string _method;
    std::string _uri;
    std::string _version;
    std::unordered_map<std::string, std::string> _headMap;
    int  _contentLength = 0;
    std::string _body;
    std::string _queryPath = WEBROOT;
    std::string _queryParameter;
};

class Response{
  public:

  private:

};

class EndPoint{
  public:
    EndPoint(int sock)
      :_sock(sock)
    {}

    ~EndPoint(){
      if (_sock > 0) {
        close(_sock);
      }
    }

    void AnalysisAndSetRequestLine(std::string s) {
      std::string method, uri, version;

      std::stringstream ss(move(s));
      
      ss >> method >> uri >> version;

      _req.SetMethod(move(method));
      _req.SetUri(move(uri));
      _req.SetVersion(move(version));
        
    }

    void AnalysisAndSetRequestHeader(std::vector<std::string> head) {
      for (size_t i = 0; i < head.size(); i++) {
          std::string key, val; 
          size_t pos = head[i].find(": ");
          key = head[i].substr(0, pos);
          val = head[i].substr(pos + 2);
          if (strcasecmp(key.c_str(), "Content-Length") == 0) {
              _req.SetContentLength(stoi(val));
          }
          _req.InsertToKVMap(move(key), move(val));
      } 
    }
    
    bool IsNeededGetBody() {
        // 没有正文情况：GET, POST && Content-Length 不存 || Content-Length = 0 
        std::string& method = _req.GetMethod();
        if (strcasecmp(method.c_str(), "GET") == 0) {
            return false;
        }

        if (strcasecmp(method.c_str(), "POST") == 0 && _req.GetContentLength() == 0) {
            return false; 
        }

        return true;
    }

    void SetRequestBody(std::string&& s) {
        _req.SetBody(std::forward<std::string>(s));
    }

    void PrintRequest() {
       _req.Print();
       std::cout << "路径: " << _req.GetQueryPath() << " 参数: " << _req.GetQueryParameter() << std::endl;
    } 
    // 获取请求
    void RecvRequest(){
      //获取请求行
      std::string requestLine = Sock::GetOneLine(_sock);  
      AnalysisAndSetRequestLine(move(requestLine));

      //获取请求报头和空行
      std::vector<std::string> header = Sock::GetRequestHeader(_sock);
      AnalysisAndSetRequestHeader(move(header));
      
      //获取正文
      if (IsNeededGetBody()) {
        std::string body = Sock::GetRequestBody(_sock, _req.GetContentLength());
        Log("Notice", body);
        SetRequestBody(move(body));
      }

    }

    // 分析请求并制作响应
    void HandlerAndMakeResponse() {
        //分析uri获取路径。
        // GET方法: uri有参数或者没有参数
        // POST方法: uri只有路径。参数在正文
        std::string queryPath, queryParameter;

        _req.GetQueryPathAndStringFromUri(queryPath, queryParameter);  


        // 制作响应
        // version code code-reason
        // Content-Length: 
        // Content-Type:
        // body
    }

    // 发送响应
    void SendResponse();

  private:
    int _sock;
    Request _req;
    Response _rsp;
};

//线程进入
class Entry{
  public:
    static void *Routine(void *args){
      pthread_detach(pthread_self());
      int sock = *(int*)args;
      delete (int*)args;

      //char buffer[10240];
      //ssize_t s = recv(sock, buffer, sizeof(buffer), 0);    
      //buffer[s] = 0;
      //std::cout << buffer << std::endl;
      //close(sock);
      
      EndPoint* ep = new EndPoint(sock);

      ep->RecvRequest();

      ep->HandlerAndMakeResponse();
      ep->PrintRequest();
      //ep->SendResponse();

      delete ep; // 短链接


      return nullptr;

    }


  private:

};
