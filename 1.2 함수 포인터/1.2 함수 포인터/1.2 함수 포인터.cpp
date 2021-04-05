// 1.2 함수 포인터.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
using namespace std;

void print(int n)
{
    cout << n << endl;
}

namespace A
{
    using namespace std;
    void print(int n)
    {
        cout << n << endl;
    }
}
class point
{
public:
    static void print(int n)
    {
        cout << n << endl;
    }
private:

};

class locate
{
    int x;
    int y;
public:
    explicit locate(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    void Print() const { cout << x << "," << y << endl; }
    void PrintInt(int n) { cout << "테스트 정수 : " << n << endl;  }
    
};
 // 서버 함수
void for_each(int* begin, int* end, void (*pf)(int))
{
    while (begin != end)
    {
        pf(*begin++);
    }
}
    
//클라이언트 함수

void print1(int n)
{
    cout << n << endl;
}

void print2(int n)
{
    cout << n * n << endl;
}



int main()
{
    void (*fp) (int);

    fp = print;

    print(3);
    fp(3);

    cout << print << endl;
    cout << fp << endl;
    cout << *fp << endl; // 메모리접근 연산자 *를 붙여도 함수 주소이다.

    // 함수 포인터 종류 : 1) 정적 함수 2) 객체로 멤버함수 호출 3) 주소로 멤버함수 호출

    // (정적 함수)
    void (*pf) (int);

    pf = print; // 1. 함수 포인터로 namespace 없는 전역 함수
    pf(10);

    pf = A::print; // 2. 함수 포인터로 namespace A의 전역함수 호출
    pf(10);

    pf = point::print; // 3. 함수 포인터로 클래스의 정적멤버함수 호출
    pf(10);

    // (객체와 주소로 멤버 함수 호출)
    // 1) 객체로 멤버 함수 호출 시 : (객체.*pf)(인자) 식으로 사용.
    // 2) 주소로 멤버 함수 호출 시 : (주소->*pf)(인자) 식으로 사용.

    locate pt(2, 3);
    locate* p = &pt;

    void (locate:: * pf1)() const; // 멤버 함수 포인터 선언
    pf1 = &locate::Print;

    void (locate:: * pf2)(int) ; // 멤버 함수 포인터 선언
    pf2 = &locate::PrintInt;

    (pt.*pf1)();
    (pt.*pf2)(5);
    cout << endl;
    (p->*pf1) ();
    (p->*pf2) (10);

    // 함수 포인터는 서버가 클라이언트로부터 정보를 전달받을 때 활용.
    // ex)

    int arr[5] = { 1,2,3,4,5 };

    for_each(arr, arr + 5, print1); // 콜백함수의 주소를 전달

    for_each(arr, arr + 5, print2); // 콜백함수의 주소를 전달

    

   


    





}

