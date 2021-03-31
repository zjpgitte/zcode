#include "string.h"

 
int main()
{
    
    zjp::string s1 = "hello world!";
    zjp::string s2 = "hello world";

    //s1 += " bit!";

    s1.insert(6, "hello ");

    //s1.push_back('!');

    s1.insert(0, 'w');

    //cout << s1.find("world") << endl;

    //cout << (s1 <  s2) <<endl;

    //s1 += '!';
    //s2 += "! hello bit!";
    cout << s1.c_str() << endl;
    //cout << s2.c_str() << endl;
    //s1 =// s2;

    //zjp::string::iterator it1 = s1.begin();
    //while(it1 != s1.end())
    //{
    //    cout << (*it1) ;
    //    it1++;
    //}
    //cout << endl;
    //zjp::string::iterator it2 = s2.begin();
    
    //while(it2 != s2.end())
    //{
    //    cout << (*it2) ;
    //    it2++;
    //}
    //cout << endl;

    //for(int i = 0; i < s1.size(); i++)
    //{
    //    cout << s1[i];
    //}
    //cout << endl;

    //for(int i = 0; i < s2.size(); i++)
    //{
    //    cout << s2[i];
    //}
    //cout << endl;

    return 0;
}
