// 연관컨테이너 map.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, int> m;
	pair<map<int, int>::iterator, bool> pr;

	m.insert(pair<int, int>(5, 100));
	m.insert(pair<int, int>(1, 30));
	m.insert(pair<int, int>(3, 20));

	map<int, int>::iterator iter;;
	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << iter->first << "," << iter->second << "  ";
	cout << endl;
	pr = m.insert(pair<int, int>(2, 60));
	if (pr.second == true)
		cout << "key: " << pr.first->first << ", " << "value: " << pr.first->second << endl;
	else
		cout << "삽입 실패!" << endl;
	
	pr = m.insert(pair<int, int>(2, 60));
	if (pr.second == true)
		cout << "key: " << pr.first->first << ", " << "value: " << pr.first->second << endl;
	else
		cout << "삽입 실패!" << endl;

	///////////////////////////////////////////////////////////
	// map은 [] 연산자를 지원한다. m[key] = value 식으로 입력하며, key가 기존에 없는 값이면 삽입, key가 기존에 있는 value를 갱신한다.
	
	m[4] = 50;  
	m[1] = 10;

	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << iter->first << "," << iter->second << "  ";
	cout << endl;
	
	///////////////////////////////////////////////////////////////

	map<int, string, greater<int>> m2; // 내림차순 조건자 greater<int>를 사용해 map 생성.

	m2[1] = 'A';
	m2[2] = 'B';
	m2[5] = 'F';
	m2[3] = 'C';

	map<int, string,greater<int>>::iterator iter2;
	for (iter2 = m2.begin(); iter2 != m2.end(); ++iter2)
		cout << iter2->first << "," << iter2->second << "  ";
	cout << endl;

	///////////////////////////////////////////////////////////////
	// 찾기 함수 : find() , lower_bound() , upper_bound() , equal_range()
	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << iter->first << "," << iter->second << "  ";
	cout << endl;
	iter = m.find(3);
	if (iter != m.end()) // find(k)로 k를 못 찾으면 끝 반복자 반환
		cout << iter->first << "," << iter->second << endl;

	map<int, int>::iterator lower_iter;
	map<int, int>::iterator upper_iter;
	lower_iter = m.lower_bound(3);
	upper_iter = m.upper_bound(3);
	cout << lower_iter->first << "," << lower_iter->second << endl;
	cout << upper_iter->first << "," << upper_iter->second << endl;

	pair<map<int, int>::iterator, map<int, int>::iterator> equal_itter;
	equal_itter = m.equal_range(3);
	cout << equal_itter.first->first << "," << equal_itter.first->second << endl;
	cout << equal_itter.second->first << "," << equal_itter.second->second << endl;


}

