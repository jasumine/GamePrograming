#include <iostream>
using namespace std;
#include <stack>
#include <vector>

const int MAX = 10000;

// vector를 안 쓴 버전
/*template<class T>
class Stack
{
public:
    Stack()
    {
        _data = new T;
    }
    void push(const T& value)
    {
        _data[_size] = value;
        _size++;
    }
    void pop()
    {
        _data[_size] = {};
        _size--;
    }
    T& top() 
    {
        return _data[_size];
    }

    bool empty()
    {
        for (int i = 0; i < _size; i++)
        {
            if (_data[i] != NULL)
                return false;
       }
    }

    int size() { return _size; }

private:
    T* _data;
    int _size = 0;
};
*/

/*template<typename T>
class Stack
{
public:
    Stack()
    {

    }
    ~Stack()
    {
        delete[] arr;
    }

    void push(const T& data)
    {
        arr[++_top] = data;
    }
    void pop()
    {
        _top--;
    }
    T top()
    {
        T temp = arr[_top];
        return temp;
    }

    bool empty()
    {
        return size() == 0;
    }

    int size() { return _top + 1; }


private:
    int _top = -1;
    T* arr = new int[MAX];
};
*/

// vector를 사용해서 구현
/*template<class T>
class SStack
{
public:
    SStack()
    {
       
    }
    void push(const T& value)
    {
        _data.push_back(value);
    }
    void pop()
    {
        _data.pop_back();
    }
    T& top()
    {
        return _data.back();
    }

    bool empty()
    {
        if (_data.empty()) return true;
    }

    int size() { return _data.size(); }

private:
    vector<T>_data;
};
*/

/*
template<class T>
class SStack
{
public:
    void push(const T& value)
    {
        _container.push_back(value);
    }
    void pop()
    {
        _container.pop_back();
    }
    T& top()
    {
        return _container.back();
    }

    bool empty() { return _container.empty(); }
    int size() { return _container.size(); }

private:
    vector<T> _container;
};
*/
// stack 구현해보기
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    while (s.empty() == false) // 비어있지 않다. 
    {
        int data = s.top(); // stack 제일 위에 있는 녀석.
        s.pop(); // 제일 위에있는 거 꺼내기.

        cout << data << endl;

        int size = s.size();
    }

}

