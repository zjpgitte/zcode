#include <iostream>
using namespace std;

//template <class T>
//T Add(const T& a, const T& b)
//{
//    return a + b;
//}

//template <class T>
//T Add(const T& a, const T& b)
//{
//    return a + b;
//}
//
//int Add(const int& a, const int& b)
//{
//    return a + b;
//}
//
//double Add(const double& a, const double& b)
//{
//    return a + b;
//}
//
//char Add(const char& a, const char& b)
//{
//    return a + b;
//}
//
//
//int main()
//{
//    int ret = Add(1, (int)2.0);
//    int ret2 = Add<int>(1, 2.0);
//
//    return 0;
//}

template <class T>
class Stack
{
public:
    Stack(int size = 0, int capacity = 15)
        :_a(new T[capacity])
        ,_size(size)
        ,_capacity(capacity)
    {
    }

    void PushBack(const T& x); //类内声明
    

    void PopBack()
    {

    }

    ~Stack()
    {
        delete[] _a;
        _size = 0;
        _capacity = 0;
    }

private:
    T *_a;
    size_t _size;
    size_t _capacity;
};

//类外定义
template <class T>  //声明模板供下面定义函数使用
void Stack<T>::PushBack(const T& x)  //类外定义函数指明是哪个类，以及是哪个模板T
{
    
}

int main()
{
    
    Stack<int> s1;

    return 0;

}






