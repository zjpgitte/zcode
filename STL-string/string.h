#pragma once
#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

namespace zjp
{
class string
{

public:
    typedef char* iterator;
public:
    void swap(string& str)
    {
        std::swap(_str, str._str);
        std::swap(_size, str._size);
        std::swap(_capacity, str._capacity);
    }
    string(char *str = "")
    {
        _size = strlen(str);
        _capacity = _size;
        _str = new char[_capacity + 1];
        strcpy(_str, str);
    }
    // string s2 = s1;
    string(const string& str)
        :_str(nullptr)
         ,_size(0)
         ,_capacity(0)
    {
        string temp(str._str);
        //swap(_str, str._str);
        //swap(_size, str._size);
        //swap(_capcity, str._capacity);
        swap(temp);
    }
    //string(const string& str)
    //{
    //    int len = strlen(str._str);
    //    _str = new char[len + 1];
    //    _size = len;
    //    _capacity = len;
    //    strcpy(_str, str._str);
    //}
    ~string()
    {
        delete[] _str;
        _str = nullptr;
        _size = _capacity = 0;
    }
    
    iterator begin()
    {
        return &_str[0];
    }

    iterator end()
    {
        return &_str[_size];
    }

    // s1 = s2
   // string& operator = (const string& str)
   // {
   //     if(_str != str._str)
   //     {
   //         delete[] _str;
   //         strcpy(_str, str._str);
   //         _size = str._size;
   //     }
   //     return *this;
   // }
   string operator = (string str)
   {
       swap(str);

       return str;
   }
        
    // s[i]
    char& operator [] (size_t i)
    {
        assert(i < _size);
        return _str[i];
    }

    const char& operator [] (size_t i) const 
    {
        assert(i < _size);
        return _str[i];
    }

    size_t size() const
    {
        return _size;
    }

    size_t capacity() const
    {
        return _capacity;
    }

    //改变容量大小
    void reserve(int capacity)
    {
        if(capacity <= capacity)
        {
            return ;
        }
        _capacity = capacity == 0 ? 1 : capacity;
        char *temp = (char*)realloc(_str, _capacity + 1);
        if(temp == nullptr)
        {
            cout << "realloc error!" << endl;
            exit(0);
        }
        _str = temp;
        
    }
    void resize(int newSize, char ch = '\0')
    {
        if(newSize > _size)
        {
            if(newSize > _capacity)
            {
                //扩容
                reserve(newSize);
            }

           while(_size != newSize)
           {
               _str[_size++] = ch;
           }
            
           _str[_size] = '\0';
        }

        _size = newSize;
        _str[_size]  = '\0';

    }

    //尾插字符
    void push_back(const char ch)
    {
        //判断是否扩容
        //if(_size == _capacity)
        //{
        //    reserve(2 * _capacity);
        //}
        //_str[_size++] = ch;

        //_str[_size] = '\0';
        insert(_size, ch);
    }

    //尾插字符串
    void append(char* str)
    {
        //if(_size + strlen(str) >  _capacity)
        //{
        //    reserve(_size + strlen(str));
        //}

        //strcpy(_str + _size, str);
        //_size += strlen(str);
        //_str[_size] = '\0';
        insert(_size, str);
    }

    string& operator += (const char ch)
    {
        push_back(ch);

        return *this;

    }

    string& operator += (char* str)
    {
        append(str);
        return *this;
    }

    //清空字符串
   void clear()
   {
       _size = 0;
       _str[_size] = '\0';
   }
    
    //打印字符串
    const char* c_str() const
    {
        return _str;
    }

    //判空
    bool empty() const
    {
        return !_size;
    }

    //比较大小
    // s1 > s2
    bool operator > (const string& s)
    {
        size_t i = 0;
        while(_str[i] && s._str[i])
        {
            if(_str[i] > s._str[i])
            {
                return true;
            }
            else if(_str[i] < s._str[i])
            {
                return false;
            }
            i++;
        }
        if(_str[i] != '\0')
        {
            return true;
        }
        else 
        {
            return false;
        }
    }

    //s1 == s2 
    bool operator == (const string& s)
    {
        if(strlen(_str) == strlen(s._str))
        {
            size_t i = 0;
            while(_str[i] != '\0' && s._str[i] != '\0')
            {
                if(_str[i] != s._str[i])
                {
                    return false;
                }
                i++;
            }
            return true;
        }
        else 
        {
            return false;
        }
    }

    //s1 < s2
    bool operator < (const string& s)
    {
        return !(*this > s || *this == s);
    }

    bool operator >= (const string& s)
    {
        return *this > s || *this == s;
    }

    bool operator <= (const string& s)
    {
        return *this < s || *this == s;
    }

    bool operator != (const string& s)
    {
        return !(*this == s);
    }

    //查找字符第一次出现的位置
    size_t find(char ch) const  
    {
        for(int i = 0; i < _size; i++)
        {
            if(ch == _str[i])
            {
                return i;
            }
        }

        return -1;
    }

    //子串匹配
    // s1.find("world");
    size_t find(const char* str) const 
    {
        char *sub = strstr(_str, str);
        return sub - _str ;
    }

    void insert(size_t pos, char ch)
    {
        assert(pos <= _size);
        if(_size == _capacity)
        {
            reserve(2 * _capacity);
        }
        int end = _size - 1;
        while(end >= (int)pos)
        {
            _str[end+1] = _str[end];
            end--;
        }
        _str[pos] = ch;
        _size++;
        _str[_size] = '\0';

    }

    void insert(size_t pos, const char* str)
    {
        assert(pos <= _size);
        if(_size + strlen(str) > _capacity)
        {
            reserve(2 * _capacity);
        }
        int end = _size - 1;
        while(end >= (int)pos)
        {
            _str[end + strlen(str)] = _str[end];
            end--;
        }
        strncpy(_str+pos, str, strlen(str));
        _size += strlen(str);
        _str[_size] = '\0';
    }

private:
    char *_str;
    size_t _size;
    size_t _capacity;
};


ostream& operator << (ostream& out, const string& s)
{
    for(int i = 0; i < s.size(); i++)
    {
        cout << s[i];
    }

    return out;
}

istream& operator >> (istream& in, string& s)
{
    if(!s.empty())
    {
        s.clear();
    }
    char ch;
    while((ch = getchar()) != '\n')
    {
        if(ch == ' ')
        {
            break;
        }
        s += ch;
    }
    return in;
}
}
