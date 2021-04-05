// 시퀀스 컨테이너 list.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

/*
list 

템플릿 형식
 template <typename T, typename Allocator=allocator<T>> class list

생성자
 1) list lt : 빈 컨테이너 생성
 2) list lt(n) : 기본값으로 초기화된 n개의 원소를 가지는 리스트 생성
 3) list lt(n,x) : 값 x 로 초기화된 n개의 원소를 가지는 리스트 생성
 4) list lt(lt2) : lt2 컨테이너를 lt로 복사
 5) list lt(b,e) : 반복자 구간 [b,e) 로 초기화된 리스트생성 

멤버 함수
 1) lt.assign(n,x) : lt에 x 값으로 n개의 원소를 할당
 2) lt.assign(b,e) : lt를 반복자 구간 [b,e)로 할당
 3) lt.front() : lt의 맨 앞 원소를 참조
 4) lt.back() : lt의 마지막 원소를 참조.
 5) p = lt.begin() : p는 lt의 첫번째 원소를 가리키는 반복자
 6) p = lt.end() : p는 lt의 마지막 원소를 가리키는 반복자
 7) lt.clear() : lt의 모든 원소 제거
 8) lt.empty() : lt가 비었는지 조사
 9) q= lt.erase(p) : p가 가리키는 원소를 제거한다. q는 다음 원소를 가리킨다.
 10) q = lt.erase(b,e) : 반복자 구간 [b,e) 가 가리키는 모든 원소를 제거한다. q는 다음 원소를 가리킨다.
 11) q= lt.insert(p,x) : p가 가리키는 위치에 원소 x 삽입. q는 삽입한 원소를 가리키는 반복자이다.
 12) lt.insert(p,n,x) : p가 가리키는 위치에 n개의 원소 x를 삽입한다.
 13) lt.insert(p,b,e) : p가 가리키는 위치에 반복자 구간 [b,e) 의 원소들을 삽입한다.
 14) x = lt.max_size() : x는 lt가 담을 수 있는 최대 원소의 갯수 (메모리의 크기) 이다.
 15) lt.merge(lt2) : lt2를 lt로 합병 정렬한다.
 16) lt.merge(lt2,pred) : lt2를 lt로 합병 정렬하되, pred 조건자를 기준으로 정렬한다.
 17) lt.push_back(x) : lt의 끝에 x를 추가한다.
 18) lt.pop_back() : lt의 끝의 원소를 제거한다.
 19) lt.push_front(x) : lt의 앞에 x를 추가한다.
 20) lt.pop_front() : lt의 앞의 원소를 제거한다.
 21) p = lt.rbegin() : p는 lt의 역순차열의 첫번째를 가리키는 반복자.
 22) p = lt.rend() : p는 lt의 역순차열의 마지막을 가리키는 반복자.
 23) lt.size() : lt의 원소 갯수
 24) lt.rsize(n) : lt의 크기를 n개로 변경. 확장되는 공간은 기본값으로 초기화
 25) lt.rsize(n,x) : lt의 크기를 n개로 변경. 확장되는 공간은 x 값을 초기화.
 26) lt.reverse() : lt 순차열을 뒤집는다.
 27) lt.sort() : lt의 모든 원소를 오름차순(less)로 정렬
 28) lt.sort(pred) : lt의 모든 원소를 pred(조건자)를 기준으로 정렬한다. (pred는 이항 조건자)
 29) lt.splice(p,lt2) : p가 가리키는 곳에 lt2의 모든 원소를 잘라 붙인다
 30) lt.splice(p,lt2,q) : p가 가리키는 곳에 lt2의 반복자 q가 가리키는 원소를 잘라 붙인다.
 31) lt.splice(p,lt2,b,e) : p가 가리키는 곳에 lt2의 반복자 구간 [b,e)의 원소를 잘라 붙인다.
 32) lt.swap(lt2) : lt와 lt2를 swap한다
 33) lt.unique() : 인접한 (양 옆의) 원소가 같다면 유일한 원소의 순차열로 만든다.
 34) lt.unique(pred) : 인접한 (양 옆의) 원소가 pred의 기준에 맞다면 유일한 원소의 순차열로 만든다. 
 35) lt.remove(x) : x 원소를 모두 제거한다.
 36) lt.remove_if(pred) : pred(단항 조건자) 가 참인 모든 원소 제거.
*/


#include "pch.h"
#include <iostream>
#include <list>
using namespace std;

bool Predicate(int n)
{
    return 10 <= n && n <= 30;
}

bool Predicate2(int x, int y)
{
    return x >= y;
}

struct Greater
{
    bool operator () (int left, int right) const // 사용자 정의한 Greater 조건자
    {
        return left > right;
    }
};

int main()
{
    list<int> lt1;

    lt1.push_back(30);
    lt1.push_back(40);
    lt1.push_back(50);

    list<int>::iterator iter;
    for (iter = lt1.begin(); iter != lt1.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    lt1.push_front(20);
    lt1.push_front(10);

    for (iter = lt1.begin(); iter != lt1.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    list<int>::iterator iter2;
    iter = lt1.begin();
    iter++;
    iter++;

    iter2 = lt1.erase(iter); // 30 제거. 삭제 된 원소 뒤의 원소를 반환.

    for (iter = lt1.begin(); iter != lt1.end(); ++iter)
        cout << *iter << " " ;
    cout << "iter2 : " << *iter2 << endl;
    
    iter = iter2;
    iter2 = lt1.insert(iter, 30); // 삽입된 원소 반환

    for (iter = lt1.begin(); iter != lt1.end(); ++iter)
        cout << *iter << " ";
    cout << "iter2 : " << *iter2 << endl;

    // vector, deque 에서는 insert, erase 를 사용하면 반복자들이 무효화됨. 메모리 재할당하기 때문.
    // list는 insert, erase를 써도 반복자가 무효화되지 않음. 메모리 재할당이 없기 때문.




    lt1.push_back(10);
    lt1.push_back(10);
    lt1.push_back(10);

    for (iter = lt1.begin(); iter != lt1.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
    lt1.remove(10); // vector, deque엔 없는 list 고유의 함수 remove(x). 순차 탐색을 통해 x 값을 가진 모든 노드를 제거한다. 
    for (iter = lt1.begin(); iter != lt1.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    lt1.remove_if(Predicate); /// remove_if (predicate) : 단항 조건자 predicate 조건에 부합하는 원소를 삭제.
        for (iter = lt1.begin(); iter != lt1.end(); ++iter)
            cout << *iter << " ";
    cout << endl;




    //////////////////////////////////////////////////////////////
    // splice ////////////////////////////////////////////////////

    list<int> lt2;
    lt2.push_back(100);
    lt2.push_back(200);
    lt2.push_back(300);
    lt2.push_back(400);

    iter = lt1.end();
    lt1.splice(iter, lt2, lt2.begin()); // lt.splice(p,lt2,q) : lt의 반복자 p 가 가리키는 곳에 lt2의 반복자 q가 가리키는 원소를 잘라 붙인다.
    for (iter = lt1.begin(); iter != lt1.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    lt1.splice(iter, lt2);  // lt.splice(p,lt2) : lt의 반복자 p가 가리키는 곳 뒤에 lt2를 이어 붙인다. lt2에 있는건 복사되는게 아니고 다 짤린다.
    for (iter = lt1.begin(); iter != lt1.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    lt2.push_back(500);
    lt2.push_back(600);
    lt1.splice(iter, lt2, lt2.begin(), lt2.end()); // lt.splce(p,lt2,b,e) : lt의 반복자 p가 가리키는 곳 뒤에 lt2의 반복자 구간 [b,e) 의 원소들을 잘라 붙인다.
    for (iter = lt1.begin(); iter != lt1.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    for (iter = lt2.begin(); iter != lt2.end(); ++iter)
        cout << *iter2 << " ";
    cout << endl;

    /////////////////////////////////////////////////////

    lt1.reverse(); // lt 배열을 뒤집는다.
    for (iter = lt1.begin(); iter != lt1.end(); ++iter)
        cout << *iter << " ";
    cout << endl;


    
    /// ////////////////////////////////////////////////
    

    lt1.push_back(40);
    lt1.push_front(600);
    for (iter = lt1.begin(); iter != lt1.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    lt1.unique(); // lt1.unique() 인접한 원소가 같다면 하나 제거하여 유일하게 만듬.
    for (iter = lt1.begin(); iter != lt1.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    list<int> lt3;
    lt3.push_back(10);
    lt3.push_back(20);
    lt3.push_back(30);
    lt3.push_back(40);
    lt3.push_back(35);

    for (iter = lt3.begin(); iter != lt3.end(); iter++)
        cout << *iter << " ";
    cout << endl;
    lt3.unique(Predicate2); // unique(predicate) : 연속한 두 원소를 매개변수로 받는 이항 조건자가 참이면 원소 제거.
        for (iter = lt3.begin(); iter != lt3.end(); iter++)
            cout << *iter << " ";
        cout << endl;
        


    /////////////////////////////////////////////////////
    /////// sort ////////////////////////////////////////

        list<int> lt4;
        lt4.push_back(10);
        lt4.push_back(30);
        lt4.push_back(20);
        lt4.push_back(50);
        lt4.push_back(40);
        for (iter = lt4.begin(); iter != lt4.end(); ++iter)
            cout << *iter << " ";
        cout << endl;
        
        lt4.sort(); // sort() : 오름차순으로 정렬.
        for (iter = lt4.begin(); iter != lt4.end(); ++iter)
            cout << *iter << " ";
        cout << endl;

        lt4.sort(greater<int>()); // sort(greater<T>()) : 내림차순 정렬
        for (iter = lt4.begin(); iter != lt4.end(); ++iter)
            cout << *iter << " ";
        cout << endl;

        list<int> lt5;
        lt5.push_back(5);
        lt5.push_back(10);
        lt5.push_back(15);


        list <int> lt6;
        lt6.push_back(1);
        lt6.push_back(2);
        lt6.push_back(3);

        cout << "lt5 : ";
        for (iter = lt5.begin(); iter != lt5.end(); ++iter)
            cout << *iter << " ";
        cout << endl;

        cout << "lt6 : ";
        for (iter = lt6.begin(); iter != lt6.end(); ++iter)
            cout << *iter << " ";
        cout << endl;

        lt5.merge(lt6); // merge(lt) : lt와 합병 정렬한다. 이 때, 두 리스트는 이미 모두 오름차순으로 정렬되어 있는 상태여야 한다. lt의 데이터는 다른편 list로 옮겨간다.(복사 X)

        cout << "lt5 : ";
        for (iter = lt5.begin(); iter != lt5.end(); ++iter)
            cout << *iter << " ";
        cout << endl;

        cout << "lt6 : ";
        for (iter = lt6.begin(); iter != lt6.end(); ++iter)
            cout << *iter << " ";
        cout << endl;

        lt6.push_back(80);
        lt6.push_back(50);
        lt6.push_back(10);

        lt5.merge(lt6, greater<int>()); // merge(lt, predicate) : 조건자 predicate를 기준으로 합병 정렬한다. 이 때, 두 리스트는 predicate 기준으로 이미 정렬된 상태여야 한다.
        return 0;
}

