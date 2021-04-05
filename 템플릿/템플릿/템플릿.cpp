// 템플릿.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <functional>
using namespace std;

template <typename T>
void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 템플릿 특수화
template <> void Swap(char* &a, char* &b)
{
    char* temp = NULL;
    strcpy_s(temp, sizeof(a), a);
    strcpy_s(a, sizeof(b), b);
    strcpy_s(b, sizeof(temp), temp);

}

// 템플릿 디폴트 매개변수 
// ex ) typename <T = int, int capT = 100>

// STL을 위한 템플릿 예제

template <typename IterT, typename Func>
void For_each(IterT begin, IterT end, Func pf)
{
    while (begin != end)
        pf(*begin++);
}

void printInt(int data)
{
    cout << data << endl;
}

void printString(string data)
{
    cout << data << endl;
}

// 함수 템플릿
template <typename T>
void Print(T data)
{
    cout << data << endl;
}

//함수 객체
template <typename T>
struct PrintFunctor
{
    string sep;

    explicit PrintFunctor(const string& s = " ") : sep(s) {}

    void operator() (T data) const
    {
        cout << data << sep;
    }
};

template <typename T>
struct Less
{
    bool operator() (T a, T b) { return a < b; }
};

template <typename T>
struct Greater
{
    bool operator() (T a, T b) { return a > b; }
};

// 매개변수 타입과 반환 형 타입을 직접 결정할 수 있는 함수 객체
template <typename RetType, typename ArgType>
class Functor
{
public:
    RetType operator() (ArgType data)
    {
        cout << data << endl;
        return RetType();
    }
};

// STL의 pair 클래스 구현
// 두 객체를 하나의 객체로 취급할 수 있는 기능

template <typename T1, typename T2>
struct Pair
{
    T1 first;
    T2 second;
    Pair(const T1& ft, const T2& sd) : first(ft), second(sd) {}
};

template <typename T>
void Copy(T dest, T src, int nSize)
{
    int i;
    for (i = 0; i < nSize; i++)
    {
        dest[i] = src[i];
    }
}

template<typename T>
class stack
{
    T buf[100];
    int top = 0;

public:
    void push(const T &data)
    {
        buf[top++] = data;
    }

    const T& pop()
    {
        return buf[--top];

    }

    bool empty() const
    {
        return top <= 0;
    }
};

template <typename T>
class Queue
{
    T buf[100];
    int front = -1;
    int rear = -1;

public:
    bool empty() const
    {
        return front == rear;
    }

    void push(T data)
    {
        buf[++rear] = data;
    }

    T pop()
    {
        if (empty())
            return NULL;
        return buf[front++];
    }
        
};

int main()
{
    int a = 1, b = 2;
    Swap(a, b); 
    cout << a << "," << b << endl;
    int arr[5] = { 10, 20 , 30 , 40 ,50 };
    string sarr[3] = { "abc", "ABCDE", "Hello!" };
    
    For_each(arr, arr + 5, printInt);        // = For_each<int* , void (*) (int)> (arr, arr+5, printInt)
    For_each(sarr, sarr + 3, printString);   // = For_each<string* , void (*) (string)> (arr, arr+3, printString)

    // 함수 템플릿
    For_each(sarr, sarr + 3, Print<string>);

    // 함수 객체
    For_each(sarr, sarr + 3, PrintFunctor<string>("\n"));
    
    cout << Less<int>()(3, 5) << endl;
    cout << less<int>() (3, 5) << endl; // STL less

    cout << Greater<int>() (5, 3) << endl;
    cout << greater<int>() (5, 3) << endl;

    ///////

    Functor<void, int> Functor1;
    Functor1(5);
    
    Functor<bool, string> Functor2;
    Functor2("Hell No");

    Pair<int, int> p1(10, 20);
    cout << p1.first << "," << p1.second << endl;

    Pair<int, string> p2(20, "Hell No");
    cout << p1.first << "," << p2.second << endl;

    int arr1[5] = { 1,2,3,4,5 };
    int arr2[5] = { 5,4,3,2,1 };
    
  

  
}

