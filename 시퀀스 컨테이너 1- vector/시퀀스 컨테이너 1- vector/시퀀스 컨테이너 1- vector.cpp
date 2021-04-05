// 시퀀스 컨테이너 1- vector.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
/*
* 템플릿 형식 :
* <typename T, typename Allocater = allocator<t>> class vector

  생성자 : 
  1) vector v  - 빈 컨테이너
  2) vector v(n) - 기본값으로 초기화된 n개의 원소 가진 컨테이너
  3) vector v(n,x) - x값으로 초기화된 n개의 원소 가진 컨테이너
  4) vector v(v2) - v2 컨테이너의 복사본 (복사 생성자 호출)
  5) vector v(b,e) - 반복자 구간 [b,e)로 초기화된 원소를 가짐. (b <= e)

  멤버함수 :
  1) v.assign(n,x) : x값으로 n개의 원소 할당.
  2) v.assign(b,e) : v를 반복자 구간 (b,e] 구간으로 할당. (const와 비const 버전이 있음. 범위 점검을 포함)
  3) v.at(i) : v의 i번째 원소를 참조. (const와 비const 버전이 있음)
  4) v.back() : v의 마지막 원소를 참조. (const와 비const 버전이 있음)
  5) p = v.begin() : p는 v의 첫원소를 가리키는 반복자. (const와 비const 버전이 있음)
  6) x=  v.capacity() : x = v에 할당된 공간의 크기.
  7) v.clear() : v의 모든 원소를 제거.
  8) v.empty() : v가 비었는지 조사.
  9) p = v.end() : p =  v의 끝을 가리키는 반복자.
  10) q = v.erase(p) : p가 가리키는 원소를 제거. q는 다음 원소.
  11) q = v.erase(b,e) : (b,e] 구간의 모든 원소를 제거. q는 다음 원소.
  12) v.front() : v의 첫번쨰 원소를 참조.
  13) q=v.insert(p,x) : p (반복자) 가 가리키는 위치에 원소 x를 삽입. q는 삽입원소를 가리키는 반복자이다.
  14) v.insert(p,n,x) : p (반복자) 가 가리키는 위치에 n개의 x값을 삽입. 삽입한 만큼 뒤의 원소들이 밀림.
  15) v.insert(p,b,e) : p (반복자) 가 가리키는 위치에 [b,e) 의 원소를 삽입.
  16) x = v.max_size() : x= v가 담을수 있는 최대 원소의 개수 (메모리 크기)
  17) v.pop_back() : 맨 뒤의 원소 제거
  18) v.push_back(x) : v의 끝에 원소 x 삽입.
  19) p = v.rbegin() : p는 v의 역 순차열의 첫번째 원소를 가리키는 반복자 (리버스 반복자)
  20) p = v.rend() : p는 v의 역 순차열의 마지막 원소를 가리키는 반복자 (리버스 반복자)
  21) v.reserve(n) : n개의 원소를 저장할 공간을 예약
  21) v.resize(n) : v의 크기를 n으로 변경하고, 확장되는 공간의 값을 기본값으로 초기화.
  22) v.resize(n,x) : v의 크기를 n으로 변경하고, 확장되는 공간의 값을 x로 초기화.
  23) v.size() : v의 원소 갯수
  24) v.swap(v2) : v와 v2를 swap한다.

  연산자 :
  1) v1 == v2 : v1과 v2의 모든 원소가 같은가? (bool 값)
  2) v1 != v2 : v1과 v2의 모든 원소 중 하나라도 다른 값이 있는가? (bool 값)
  3) v1 < v2 : v1과 v2의 원소를 각각 일대일 대응으로 비교하다가 서로 다른 값이 발견되었을 때 대소를 비교. 한쪽 벡터가 짧아서 중간에 비교가 끝나면, 긴 쪽을 큰 것으로 판별. (bool 값)
  4) v1 <= v2 : v1 < v2 연산자에서 대소비교만 <=로 바뀜. (bool 값)
  5) v1 > v2 : 3) v1< v2 참고
  6) v1 >= v2 : 3) v1 < v2 참고
  7) v[i] : v의 i번째 원소 참조 (const, 비const 버전이 있으며 범위 점검이 없음.)

  */







int main()
{
   
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    for (vector<int>::size_type i = 0; i < v.size(); ++i)
    {
        cout << v[i] << endl;
    }

    cout << typeid(vector<int>::size_type).name() << endl; // typeid(~~).name 은 괄호안의 자료형을 const char* 형식으로 반환

    cout << v.size() << endl;
    cout << v.capacity() << endl; // capacity() 는 벡터만이 유일하게 가지는 함수. 
    cout << v.max_size() << endl;
    /* capacity()의 존재 이유 : vector는 원소의 추가/제거가 배열의 맨 뒤에서만 일어난다. 원소가 추가될 때마다 메모리가 자라나게 하려면 메모리를 재할당 해야 한다.
    *  메모리를 재할당하고 이전 원소를 복사하는 것은 비효율적인데 그나마 이 성능 문제를 보완해주는 것이 capacity() 멤버 함수이다. 원소가 추가될 때마다, capacity()의
    * 값을 기준으로 넉넉한 메모리 공간을 미리 마련해둔다. (추가될 때마다 일일히 메모리 재할당하지 않는다.)
    * 
    * capacity() 를 활용한 메모리 확장 정책 기준 : 현재 capacity() 의 값이 size() 보다 크지 않을 때, 원소를 추가하려하면  ( capacity / 2 ) 만큼 추가 메모리 할당.
    * 
    *  cf) reserve(n) : n개의 메모리 공간을 미리 할당한다. 
    */

    // capacity() 의 용례
    v.reserve(8);

    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
    v.push_back(60);
        cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
        v.push_back(70);
        cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
        v.push_back(80);
        cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
        v.push_back(90);
        cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
        v.push_back(100);
        cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
        v.push_back(110);
        cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
        v.push_back(120);
        cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
        v.push_back(130);
        cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;

        for (vector<int>::size_type i = 0; i < v.size(); ++i)
        {
            cout << v[i] << endl;
        }
        cout << endl;

        vector<int> v2(5); // 0 (디폴트 값) 으로 초기화된 size 5의 벡터 생성
        for (vector<int>::size_type i = 0; i < v2.size(); ++i)
        {
            cout << v2[i] << " " << endl;
        }

        vector<int> v3(5, 10); // 10으로 초기화된  size 5의 벡터 생성
        for (vector<int>::size_type i = 0; i < v3.size(); ++i)
            cout << v3[i] << " " << endl;

        v3.resize(10); // size 5 인 벡터 컨테이너를 size 10 으로 확장. 인덱스 5부터 디폴트값으로 설정.
        cout << "size: " << v3.size() << " " << "capacity: " << v3.capacity() << endl;
        for (vector<int>::size_type i = 0; i < v3.size(); ++i)
            cout << v3[i] << " " << endl;
        v3.resize(11, 3); // size 11로 확장. 단, 확장된 부분의 값은 3이 됨.
        cout << "size: " << v3.size() << " " << "capacity: " << v3.capacity() << endl;
        for (vector<int>::size_type i = 0; i < v3.size(); ++i)
            cout << v3[i] << " " << endl;

        v3.clear(); // clear는 벡터를 비우지만 (size = 0 이 됨), 메모리를 제거하지는 못한다. (capacity는 0이 되지 않음.) 
        cout << "size: " << v3.size() << " " << "capacity: " << v3.capacity() << endl;
        for (vector<int>::size_type i = 0; i < v3.size(); ++i)
            cout << v3[i] << " " << endl;
        if (v3.empty())
            cout << "v3는 비었습니다" << endl;

        // ★메모리까지 제거하는 방법. (capacity()의 값을 0으로 만들기)
        vector<int>().swap(v3); //  ★ 벡터의 기본 생성자 활용! vector의 임시 객체(capacity 0)와 제거하려는 벡터를 swap()! 
        cout << "size: " << v3.size() << " " << "capacity: " << v3.capacity() << endl;







        v.swap(v2);
        for (vector<int>::size_type i = 0; i < v.size(); ++i)
        {
            cout << v[i] << endl;
        }
        for (vector<int>::size_type i = 0; i < v2.size(); ++i)
        {
            cout << v2[i] << " " << endl;
        }


        v2.front() = 1; v2.back() = 2; v2.at(3) = 3; v2[4] = 4; // front, back , at , []연산자 이용해 벡터의 값 수정 가능. 단, at() 는 범위 점검을 하며, [] 연산자는 범위 점검 안함.




        vector<int> v4(5, 1);
        for (vector<int>::size_type i = 0; i < v4.size(); ++i) { cout << v4[i] << endl; }
        v4.assign(5, 2); // assign : n개의 원소에 x값 할당.
        for (vector<int>::size_type i = 0; i < v4.size(); ++i) { cout << v4[i] << endl; }


        // 반복자

        vector<int> v5;
        v5.push_back(10);
        v5.push_back(20);
        v5.push_back(30);
        v5.push_back(40);
        v5.push_back(50);

        for (vector<int>::iterator iter = v5.begin(); iter != v5.end(); ++iter)
            cout << *iter << endl;

        vector<int>::iterator iter = v5.end();
        iter -= 2; // 반복자 증감 연산자
        cout << *(iter) << endl;
        vector<int>::const_iterator citer = v5.begin(); // 상수 반복자 const_iterator 는 값 수정을 못함. ex) *citer = 50; 불가


        // const 반복자 종류와 비교
        /*
        * 1) vector<int>::iterator iter : iter는 다음 원소로 이동 가능하고, 값 수정 가능. int* p = arr 에서 p처럼 동작.
        * 2) vector<int>:: const_iterator citer : citer는 다음 원소로 이동가능하고, 값 수정 불가능. const int* cp = arr 에서의 cp 처럼 동작.
        * 3) const vector<int>::iterator iter_const : iter_const는 다음 원소로 이동불가능하고, 값 수정 가능. int* const p_const = arr 에서의 p_const 처럼 동작.
        * 4) const vector<int>::const_iterator cp_const : cp_const는 다음 원소로 이동불가능하고, 값 수정도 불가. const int* const cp_const = arr 에서의 cp_const처럼 동작.   
        */
        

        // 역방향 반복자
        vector<int>::reverse_iterator riter;
        for (riter = v5.rbegin(); riter != v5.rend(); ++riter)
            cout << *riter << endl;

        // insert 함수

        vector<int>::iterator Iter = v5.begin() + 2;
        vector<int>::iterator Iter2 = v5.insert(Iter, 100); // 반복자 iter가 가리키는 자리 바로 앞에 100 삽입. 그리고 삽입된 자리를 가리키는 반복자 반환 
        for (Iter = v5.begin(); Iter != v5.end(); ++Iter)
            cout << *Iter << " ";

        cout << "Iter2 : " << *Iter2 << endl;

        Iter2 -= 2;
        v5.insert(Iter2, 3, 50); // Iter2 가 가리키는 자리 바로 앞 위치에 3개의 원소 (값 50)를 삽입.
        for (Iter = v5.begin(); Iter != v5.end(); ++Iter)
            cout << *Iter << " ";
        cout << endl;

        // insert (p,b.e) 구간 설정 함수

        vector<int> v6;
        v6.push_back(1);
        v6.push_back(2);
        v6.push_back(3);
        v6.push_back(4);
        v6.push_back(5);

        Iter = v6.begin();
        v6.insert(Iter, v6.rbegin(), v6.rend());
        for (Iter = v6.begin(); Iter != v6.end(); Iter++) 
        {
            cout << *Iter << " ";
        }
        cout << endl;
        // erase 함수

        Iter = v6.erase(v6.begin()); // erase(p) 반복자가 가리키는 부분의 원소를 제거 후, 다음 원소를 가리키는 반복자를 제거.
        for (Iter = v6.begin(); Iter != v6.end(); Iter++)
        {
            cout << *Iter << " ";
        }
        cout << endl;

     
        Iter2 = v6.erase(v6.begin(), v6.begin() + 4); // erase(b,e) : b,e 구간의 원소를 제거
        for (Iter = v6.begin(); Iter != v6.end(); Iter++)
        {
            cout << *Iter << " ";
        }
        cout << "Iter : " << *Iter2 << endl;
        
    // 반복자로 동작하는 생성자와 멤버 함수 assign()

        vector<int> v7(v6.begin(), v6.end()); // 순차열 [v6.begin(), v6.end())로 v7을 초기화.
        for (iter = v7.begin(); iter != v7.end(); ++iter) 
            cout << *iter << " ";
        cout << endl;

        vector<int> v8;
        v8.assign(v7.begin(), v7.end()); // v8에 [v7.begin(),v7.end()) 를 할당.
        for (iter = v8.begin(); iter != v8.end(); ++iter)
            cout << *iter << " ";
        cout << endl;

        // vector와 vector 의 비교

        cout << (v7 == v8) << endl;
        cout << (v7 != v8) << endl;
        cout << (v7 < v8) << endl;

        return 0;
}

