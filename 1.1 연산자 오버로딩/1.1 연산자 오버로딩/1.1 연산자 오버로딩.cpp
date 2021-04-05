// 1.1 연산자 오버로딩.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include "pch.h"
#include <iostream>
#include <cstring>
using namespace std;

class point
{
public:
    point(int x_, int y_) : x(x_), y(y_)
    {

    }
    ~point()
    {}

    const point operator+(const point& arg) const 
    {
        return point(this->x + arg.x, this->y + arg.y);
    }

    const point operator- (const point& arg) const
    {
        return point(this->x - arg.x, this->y - arg.y);
    }

    void print() const {
        cout << x << ", " << y << endl;
    }

    const point operator++()  // 전위
    {
        ++x;
        ++y;
        return *this;
    }

    const point operator++(int) // 후위
    {
        point tmp(x, y);
        ++x;
        ++y;
        return tmp;
    }

    const point operator-- ()

    {
        --x;
        --y;
        return *this;
    }

    const point operator--(int)
    {
        point tmp(x, y);
        --x;
        --y;
        return tmp;
    }

    const bool operator != (const point &arg)
    {
        if ((this->x != arg.x) || (this->y != arg.y))
            return 1;

        return 0;
    }

    int operator [] (int idx)
    {
        if (idx == 0)
        {
            return x;
        }
        else if (idx == 1)
            return y;

        else
            return NULL;
    }

    int operator [] (int idx) const
    {
        if (idx == 0)
        {
            return x;
        }
        else if (idx == 1)
            return y;
    }

    int getX() const{ return x; }
    int getY() const { return y; }


private:
    int x;
    int y;
};

typedef struct FuncObject
{
public:
    void operator() (int arg) const
    {
        cout << arg << endl;
    }
} Funcobject;


void print1(int arg)
{
    cout << arg << endl;
}



int main()
{
    point a(1, 2);
    void (*print2) (int) = print1; // 함수 포인터.
    FuncObject print3;

    print1(10); // 함수
    print2(10); // 함수 포인터
    print3(10); //  함수 객체.  = print3.operator(10)

    
    
   

}
