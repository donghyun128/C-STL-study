// 원소를 수정하지 않는 알고리즘.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

/*
* p = adjacent_find(b,e) : p는 구간 [b,e)에서 *p = *(p+1)인 첫원소를 가리키는 반복자
* p = adjacent_find(b,e,f) : p는 구간 [b,e)에서 이항조건자 f(*p,*(p+1))가 참이 되는 첫 원소를 가리키는 반복자
* n = count(b,e,x) : [b,e) 구간의 원소 중 x의 갯수
* n = count_if(b,e,f) : [b,e) 구간의 원소 중 단항 조건자 f(*p)를 만족하는 원소의 갯수
* equal(b,e,b2) : [b,e)와 [b2, b2+(e-b))의 의 모든 원소가 같은가?(==)
* equal(b,e,b2,f) : [b,e)와 [b2, b2+(e-b)의 모든 원소가 조건자 f(*p,*q)에서 참인가?
* p=find(b,e,x) : 구간 [b,e)에서 맨 처음 원소가 x인 부분을 가리키는 반복자 
* p=find_end(b,e,b2,e2) : p는 구간 [b,e)의 순차열 중 구간 [b2,e2)의 순차열과 일치하는 구간의 첫원소를 가리키는 반복자. 일치하는 구간이 여러개면 가장 마지막 구간의 첫 원소 반복자 반환
* p=find_end(b,e,b2,e2,f) : p는 구간 [b,e)의 순차열 중에서 구간 [b2,e2)과 이항 조건자 f를 만족하는 순차열의 첫원소를 가리키는 반복자. 여러개면 가장 마지막 구간의 첫 원소 반환
* p=find_first_of(b,e,b2,e2) : p는 구간 [b,e) 중에서 구간 [b2,e2)의 원소 중 같은 원소가 발견되었을 때 그 첫 원소를 가리키는 반복자
* p=find_first_of(b,e,b2,e2,f) : p는 구간 [b,e) 중에서 구간 [b2,e2)의 원소 중에서 조건자 f를 만족하는 원소가 발견되었을 때 그 첫원소를 가리키는 반복자.
* p=find_if(b,e,f): p는 구간 [b,e)에서 조건자 f(*p)가 참인 첫 원소를 가리키는 반복자
* f=for_each(b,e,f) : 구간 [b,e)에 f(*p) 동작을 적용한다. f는 다시 반환해준다.
* lexicographical_compare(b,e,b2,e2) : 구간 [b,e)의 순차열이 구간 [b2,e2)의 순차열보다 적으면(less) true, 아니면 false  반환. (적음은 사전 순임.)
* lexicographical_compare(b,e,b2,e2,f) : 구간 [b,e)의 순차열이 구간 [b2,e2)의 순차열보다 적으면(less) true, 아니면 false 반환.p가 [b,e)반복자,q가 [b2,e2) 반복자일때, 적음은 조건자 f(*p,*q)가 참임.
* k = max(a,b) : a,b 중 큰 거 반환
* k = max(a,b,f) : f(a,b)를 기준으로 큰 것 반환
* p = max_element(b,e) : p는 구간 [b,e)에서 가장 큰 원소 가리키는 반복자
* p = max_element(b,e,f) : p는 구간 [b,e)에서 가장 큰 원소 가리키는 반복자. 이 때 비교는, f를 기준으로 한다.
* k = min(a,b) : k는 a,b 중 작은 것
* k = min(a,b,f) : k는 a,b중 f를 기준으로 작은 것
* p = min_element(b,e) : p는 구간 [b,e) 중 가장 작은 원소 가리키는 반복자
* p = min_element(b,e,f) : p는 구간 [b,e) 중 가장 작은 원소 가리키는 반복자. 이 때 비교는, f 기준으로 한다.
* pair(p,q)=mismatch(b,e,b2) : (p,q)는 구간 [b,e)와 구간 [b2,b2+(e-b)) 중 !(*p == *q)가 참인 첫 원소를 가리키는 반복자의 쌍.
* pair(p,q) =mismatch(b,e,b2) : (p,q)는 구간 [b,e)와 구간 [b2,be+(e-b)) 중 !f(*p,*q)가 참인 첫 원소를 가리키는 반복자의 쌍.
* p = search(b,e,b2,e2) : 구간 [b,e)의 순차열 중 구간 [b2,e2)의 순차열과 일치하는 순차열의 첫 원소 반복자. (find_end와 다르게, 일치하는 순차열이 두개이상이면 맨처음 순차열 쪽의 첫 원소 반복자 반환.)
* p = search(b,e,b2,e2,f) : p는 구간 [b,e)의 순차열 중 구간 [b2,e2)의 순차열과 일치하는 순차열의 첫 원소 반복자. 단, 비교는 f로 한다.
* p = search_n(b,e,n,x) : p는 구간 [b,e)의 원소 중 x 값이 n개 연속한 구간의 첫 원소 가리키는 반복자.
* p = search_n(b,e,n,x) : p는 구간 [b,e)의 원소 중 f(*p,x)가 참인 값이 n개 연속한 구간의 첫 원소 가리키는 반복자.

*/



#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool Pred(int a, int b)
{
    return abs(b - a) > 20;
}

bool Pred2(int n)
{
    return n > 30;
}

bool Pred3(int a, int b) {
    return (a <= b);
}

void Print(int n)
{
    cout << n << " ";
}

template <typename T>
class Greater
{
public:

    bool operator() (const T& left, const T& right) const 
{
    return (left > right);
}

};

class point
{
private:
    int x, y;

public:
    explicit point(int x_ = 0, int y_ = 0) : x(x_), y(y_) {};
    int getX() const { return x; }
    int getY() const { return y; }
    void print() { cout << x<< ", " << y << endl; }
};

bool compar(const point& L, const point& R)
{
    if (L.getX() < R.getX())
        return true;
    else if (L.getX() > R.getX())
        return false;
    else
        return (L.getY() > L.getY());
}


int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(20);
    v.push_back(40);
    v.push_back(60);
    v.push_back(70);
    v.push_back(80);
    v.push_back(20);

    vector<int> v2;
    v2.push_back(60);
    v2.push_back(70);
    v2.push_back(80);
    v2.push_back(50);
    vector<int>::iterator iter;
    iter = adjacent_find(v.begin(), v.end());
    cout << *iter << endl;
    cout << *(iter + 1) << endl;

    vector<int>::iterator iter2;
    iter2 = adjacent_find(iter + 2, v.end());
    cout << *(iter2-1) << endl;
   
    iter2 = adjacent_find(v.begin(), v.end(), Pred);
    cout << *iter2 << endl;

    cout << count(v.begin(), v.end(), 20) << endl;

    cout << count_if(v.begin(), v.end(), Pred2) << endl;
    iter = v.begin()+4;
    if (equal(iter, v.end(), v2.begin()))
        cout << "O" << endl;
    else 
        cout << "X"<<endl;
    iter = v.begin() + 3;
    if (equal(v.begin(), iter, v2.begin(), Pred3))
        cout << "O" << endl;
    else cout << "X"<<endl;

    iter = find(v.begin(), v.end(), 40);
    cout << *iter << "," << *(iter + 1) << endl;

    iter = find_if(v.begin(), v.end(), Pred2);
    cout << *iter << endl;

    vector<int> v3;
    vector<int> v4;
    v3.push_back(10);
    v3.push_back(20);
    v3.push_back(30);
    v3.push_back(100);
    v3.push_back(10);
    v3.push_back(20);
    v3.push_back(30);
    v3.push_back(40);

    
    v4.push_back(10);
    v4.push_back(20);
    v4.push_back(30);

    iter = find_end(v3.begin(), v3.end(), v4.begin(), v4.end());
    cout << *(iter + 3) << endl;

    iter =find_first_of(v.begin(), v.end(), v2.begin(), v2.end());
    cout << *iter << endl;
    cout<<*(iter - 1) << endl;

    for_each(v3.begin(), v3.end(), Print);

    class PrintFunctor {
    private:
        char fmt;
    public:

        explicit PrintFunctor(char c = ' ') : fmt(c) {};
        void operator () (int n)
        {
            cout << n << fmt;
        }
    };

    for_each(v4.begin(), v4.end(), PrintFunctor('&'));
    cout << endl;

    vector<int> v5;
    v5.push_back(40);
    v5.push_back(50);
    v5.push_back(60);

    if (lexicographical_compare(v4.begin(),v4.end(),v5.begin(),v5.end()))
        cout << "O" << endl;
    else
        cout << "X" << endl;

    if (lexicographical_compare(v5.begin(), v5.end(), v4.begin(), v4.end(),Greater<int>()))
        cout << "O" << endl;
    else
        cout << "X" << endl;

    cout << *(min_element(v5.begin(), v5.end())) << endl;
    cout << *(max_element(v5.begin(), v5.end()))<< endl;

    vector<point> vp;
    vp.push_back(point(10, 20));
    vp.push_back(point(30, 40));
    vp.push_back(point(50, 40));
    vector<point>::iterator iterV;
    iterV = max_element(vp.begin(), vp.end(), compar);
    (*iterV).print();



    return 0;

}

