

#include "pch.h"
#include <iostream>
#include <deque>
#include <vector>
using namespace std;
 /*
* Deque 컨테이너
* 
* 템플릿형식 : template <typename T, typename Allocator=allocator<T>> class deque
* 
 생성자
* 1) deque dq : 빈 컨테이너 생성
* 2) deque dq(n) : dq는 기본값으로 초기화된 n개의 원소를 가짐
* 3)deque dq(n,x) : x 값으로 초기화된 n개의 원소를 가짐.
* 4) deque dq(dq2) : dq2 컨테이너 복사본 생성 (복사 생성자 호출.)
* 5) deque dq(b,e) : dq는 반복자 구간 [b,e)로 초기화된 원소를 가짐
* 
멤버 함수
* 1) dq.assign(n,x) : dq에 x 값으로 n개의 원소를 할당
  2) dq.assign(b,e) : dq를 반복자 구간 [b,e)로 할당.
  3) dq.at[i] : dq의 i번째 원소를 참조 (범위 점검 포함. const 버전과 비 const 버전이 존재.)
  4) dq.back() : dq의 마지막 원소를 참조.
  5) p = dq.begin() : p는 dq의 첫 원소를 가리키는 반복자.
  6) p = dq.end() : p는 dq의 끝 원소를 가리키는 반복자.
  7) dq.clear() : 모든 원소 제거.
  8) dq.empty() : dq가 비었는지 조사.
  9) q = dq.erase(p) : 반복자 p가 가리키는 원소 제거 후, 다음 원소 반환.
  10) q= dq.erase(b,e) : 반복자 구간 [b,e)의 모든 원소를 제거. q는 다음 원소.
  11) dq.front() : dq의 첫번째 원소 참조 (const와 비 const 멤버 있음.)
  12) q = dq.insert(p,x) : p가 가리키는 위치에 원소 x를 삽입. q는 삽입 원소를 가리키는 반복자.
  13) dq.insert(p,n,x) : p가 가리키는 위치에 n개의 원소 x를 삽입.
  14) dq.insert(p,b,e) " p가 가리키는 위치에 반복자 구간 [b,e)의 원소를 삽입.
  15) x = dq.max_size() : x = dq가 담을 수 있는 최대 원소 개수 (메모리 크기)
  16) dq.pop_back() : dq의 마지막 원소 제거
  17) dq.pop_front() : dq의 첫 원소 제거
  18) dq.push_back(x) : dq의 끝에 원소 x 삽입.
  19) dq.push_front(x) : dq의 앞쪽에 원소 x 삽입.
  20) p = dq.rbegin() : p는 역순차열의 첫번째 반복자
  21) p = dq.rend() : p는 역순차열의 마지막 반복자.
  22) dq.rsize(n) : dq의 크기를 n으로 변경하고, 확장되는 부분의 값 기본값으로 초기하..
  23) dq.rsize(n,x) : dq의 크기를 n으로 변경하고, 확장되는 부분의 값을 x로 초기화.
  24) dq.size() : dq 원소의 갯수
  25) dq.swap(dq2) : dq와 dq2를 swap.

  연산자
  1) dq1 == dq2
  2) dq1 != dq2
  3) dq1 < dq2
  4) dq1 > dq2
  5) dq[i]
*/


int main()
{
	deque<int> dq1;

	for (deque<int>::size_type i = 0; i < 10; ++i)
		dq1.push_back((i+1)*10);
	
	for (deque<int>::size_type i = 0; i < dq1.size(); ++i)
		cout << dq1[i] << ' ';

	cout << endl;

	dq1.push_front(5);
	dq1.push_front(0);

	for (deque<int>::size_type i = 0; i < dq1.size(); ++i)
		cout << dq1[i] << ' ';
	cout << endl;
	deque<int>::iterator iter;

	for (iter = dq1.begin(); iter != dq1.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	iter = dq1.begin() + 2;
	cout << *iter << endl;

	iter += 2;
	cout << *iter << endl;

	cout << endl;
	return 0;
}

