

#include "pch.h"
#include <iostream>
#include <set>
using namespace std;
/*
* set 컨테이너
* 
* 템플릿 형식 : template <Typename Key, typename Pred=less<key>,typename Allocator=allocator<key>> class set
* 
 생성자 :
* 1) set s : 빈 컨테이너
* 2) set s(pred) : pred 조건자 기준으로 정렬하는 set 생성
* 3) set s(s2) : s2 컨테이너의 복사본 생성
* 4) set s(b,e) : [b,e) 반복자 구간의 원소로 초기화된 set 생성
* 5) set s(b,e,pred) : [b,e) 반복자 구간의 원소로 초기화된 set 생성. 단, pred 조건자 기준으로 정렬한다.

 멤버 함수:
* 1) p = s.begin()
* 2) p - s.end()
* 3) s.clear()  : s의 원소를 전부 제거..
* 4) s.empty()  : s가 비었는지 조사.
* 5) s.count(k) : 원소 k의 갯수를 반환
* 6) q = s.erase(p) : p가 가리키는 원소를 제거한다. q는 그 다음 원소를 가리킨다.
* 7) q = s.erase(b,e) : 반복자 구간 [b,e) 가 가리키는 원소들을 제거한다. q는 그 다음 원소를 가리킨다.
* 8) n = s.erase(k) : k 원소를 모두 제거한다. n은 제거한 원소의 갯수다.
* 9) p = s.find(k) : p는 k 원소를 가리키는 반복자다.
* 10) ★ pr = s.insert(k) : s에 원소 k를 삽입한다. pr는 삽입된 원소 k를 가리키는 반복자와 성공 여부를 가리키는 bool 값인 pair 객체이다.
* 11) q = s.insert(p,k) : p가 가리키는 위치에 빠르게 k를 삽입ㄴ한다. q는 삽입한 원소를 가리키는 반복자이다.
* 12) s.insert(b,e) : 반복자 구간 [b,e)의 원소를 삽입한다.
* 13) n = s.max_size() : n은 s가 담을 수 있는 최대 원소의 갯수(메모리 크기)
* 14) s.size() : s 원소의 갯수
* 15) p = s.rbegin()
* 16) p = s.rend()
* 17) s.swap(s2) : s 와 s2 를 서로 swap
* 18) p = s.lower_bound(k) : p는 k 원소가 있는 시작 구간을 나타내는 반복자. (k를 가리키는 반복자.)
* 19) p = s.upper_bound(k) : p는 k 원소의 끝구간을 나타내는 반복자. (k가 있다면, k 가리키는 반복자의 바로 다음 반복자.). upper_bound(k) = lower_bound(k) 라면 찾는 원소 없는 것임.
* 20) pr = s.equal_range(k) : pr은 k 원소의 반복자 구간인 pair 객체다. lower_bound(k)와 upper_bound(k) 를 합친 함수. pr.first는 lower_boud(k) , pr.second는 upper_bound(k)라고 할 수 있음. 
* 21) pred = s.key_comp() : pred는 s의 key정렬 조건자
* 22) pred = s.value_comp() : s.key_comp()와 같다.
*
 */
int main()
{
    set<int> s;

    s.insert(30);
    s.insert(50);
    s.insert(10);
    s.insert(70);
    s.insert(20);
    s.insert(40);

    set<int>::iterator iter;
    for (iter = s.begin(); iter != s.end(); ++iter)
        cout << *iter << " ";  // cf) 중위 순회로 탐색함.
    cout << endl;

    s.insert(50); // set은 중복원소를 받지 않는다. 
    for (iter = s.begin(); iter != s.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    pair<set<int>::iterator, bool> pr; // pair 클래스 선언. pr.first는 set의 반복자, pr.second는 삽입 성공여부 bool값을 가진다.
    pr = s.insert(25);
    if (pr.second == true)
        cout << "삽입 성공" << endl;
    else
        cout << *pr.first << "이 이미 있습니다." << endl;


    for (iter = s.begin(); iter != s.end(); ++iter)
        cout << *iter << " ";
    cout << endl;


    pr = s.insert(25);
    if (pr.second == true)
        cout << "삽입 성공" << endl;
    else
        cout << *pr.first << "이 이미 있습니다." << endl;


    pr = s.insert(90);
    s.insert(pr.first, 85); // 90 원소의 반복자에서 검색 시작후 삽입
    for (iter = s.begin(); iter != s.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    ////////////////////////////////////////////////////////////////////////////

   

    set<int, greater<int>> s2; // 오름차순(greater) 정렬기준 사용

    s2.insert(10);
    s2.insert(40);
    s2.insert(30);
    s2.insert(50);
    s2.insert(20);

    for (iter = s2.begin(); iter != s2.end(); ++iter)
        cout << *iter << " ";
    cout << endl;


    // key_comp() , value_comp() : set의 정렬기준 조건자를 반환하는 함수. set은 원소가 key 라서 value_comp()와 key_comp()가 사실상 같다.
    cout << typeid(s.key_comp()).name() << endl;
    cout << typeid(s.value_comp()).name() << endl;
    cout << typeid(s2.key_comp()).name() << endl;
    cout << typeid(s2.value_comp()).name() << endl;

    //////////////////////////////////////////////////////////////////////////////////
    // ★연관 컨테이너의 핵심은 찾기 함수이다. ex) count() , find() , lower_bound() , upper_bound() , equal_range() 
    // 탐색할 때, 정렬 기준이 있으므로 로그시간 복잡도를 가진다.
    // 찾기 멤버함수의 기준 : (a == b)이 아님. !(a>b) && !(b<a) 임.
    
    cout << "s에서 원소 30의 갯수: "<< s.count(30) << endl; // s.count(30) : s에서 30의 갯수 출력
         
    iter = s.find(30); // s.find(30) : 원소 30을 가리키는 반복자를 반환
    cout << *iter << endl;
    iter = s.find(100); // 만약 원소가 없다면, 끝표시 반복자 ( s.end() )를 반환한다.
    if (iter == s.end())
        cout << "100은 s에 없음" << endl;
     

    set<int>::iterator lower_iter;
    set<int>::iterator upper_iter;

    lower_iter = s.lower_bound(50); // s.lower_bound(50): s에서 50을 가리키는 반복자 지시
    upper_iter = s.upper_bound(50); // s.upper_bound(50) : s에서 50을 가리키는 반복자 바로 다음 반복자 지시
    cout << *lower_iter << endl;
    cout << *upper_iter << endl;
    lower_iter = s.lower_bound(18);
    upper_iter = s.upper_bound(18);
    if (lower_iter == upper_iter) // 찾으려는 원소가 없으면 lower_bound() , upper_bound() 이 같아진다.
        cout << "18은 s에 없음!" << endl;

    // s.equal_range() : lower_bound 와 upper_bound 의 짬뽕이다. 
    pair<set<int>::iterator, set<int>::iterator> pr2; // equal_range는 pr.first 와 pr.second 가 반복자인 페어에 반환된다.
    pr2 = s.equal_range(50);  
    cout << *pr2.first << endl;
    cout << *pr2.second << endl;

    pr2 = s.equal_range(18);
    if (pr2.first == pr2.second) // 찾고자하는 원소가 없다면, first와 second가 같아진다.
        cout << "18은 s에 없음!" << endl;

    return 0;
}
