// 함수 객체.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
using namespace std;
class Equal
{
public:

    bool operator() (int a, int b) { return (a == b);}
    // () 는 함수 연산자
    // 객체에 () 연산자를 사용하여 함수 객체 이용 가능.
    // 인라인화 되어 일반 함수보다 빠르다.
};

class Adder
{
public:
    int operator() (int a, int b) { return a + b; }
};

int main()
{
    
    Equal cmp;
    cout << cmp(10, 20) << endl;
    Adder add;
    int sum = add(10, 20);
    cout << sum;
}
