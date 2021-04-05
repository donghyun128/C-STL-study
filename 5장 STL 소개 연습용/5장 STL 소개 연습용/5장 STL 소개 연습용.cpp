// 5장 STL 소개 연습용.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <functional>
using namespace std;

int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	vector<int>::iterator iter = v.begin();

	cout << iter[0] << endl;
	cout << iter[1] << endl;
	cout << iter[2] << endl;
	cout << iter[3] << endl;
	cout << endl;

	iter += 2;
	cout << *iter << endl;
	cout << endl;

	vector<int>::iterator iter2 = iter + 1;
	cout << *iter2 << endl;

	deque<int> dq;

	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);
	dq.push_back(40);
	deque<int>::iterator dqIter1 = dq.begin();

	for (dqIter1; dqIter1 != dq.end(); dqIter1++)
		cout << *dqIter1 << endl;

	iter = find(v.begin(), v.end(), 100);
	if (iter == v.end())
		cout << "NULL" << endl;
	else cout << *iter << endl;

	vector<int> v2;
	v2.push_back(5);
	v2.push_back(3);
	v2.push_back(6);		
	v2.push_back(2);
	v2.push_back(13);

	

	sort(v2.begin(), v2.end(), less<int>()); // sort 함수. 이 것은 오름차순 정렬이다. 세번째 인자에 따라 정렬 기준 변경이 가능.
	for (vector<int>::iterator iterV = v2.begin(); iterV != v2.end(); ++iterV)
	{
		cout << *iterV << " ";
	}

	stack<int, vector<int>> st; // vector 컨테이너를 이용한 stack 컨테이너 어뎁터
	
	st.push(10);
	st.push(20);
	st.push(30);

	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);


	reverse_iterator<vector<int>::iterator> riter(vec.end()); // 역방향 반복자
	reverse_iterator<vector<int>::iterator> riter_end(vec.begin());

	for (; riter != riter_end; riter++) // 역방향 반복자는 ++ 해버리면 역방향으로 간다.
	{
		cout << *riter << " ";
		cout << endl;
	} // ※ 역방향 반복자는 가리키는 원소 다음의 원소값을 참조한다! ([5]를 가리키면 [4]의 값을 참조.)


	 // rbegin() : (역방향 기준)첫 원소를 가리키는 역방향 연산자 반환   (순방향으로는 마지막 원소)
	// rend()  : (역방향 기준) 마지막 원소를 가리키는 역방향 연산자 반환 (순방향으로는 첫번째 원소)
	reverse_iterator<vector<int>::iterator> Riter(vec.rbegin()); 
	for (; Riter != vec.rend(); Riter++)
	{
		cout << *Riter << "";
		cout << endl;
	}

	// 함수 어댑터
	// ex) not1 , not2 : 함수 결과와 반대 의미인 함수 객체를 반환. not1 은 피연산자 한개인 단항연산자, not2는 다항연산자에 쓴다.
	// 

	cout << not2(less<int>())(20,50)<< endl;
	cout << not2(less<int>())(50, 20) << endl;





	return 0;
}
