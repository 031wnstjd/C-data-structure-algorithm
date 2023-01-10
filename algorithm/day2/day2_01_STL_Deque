#include <iostream>
#include <deque>

using namespace std;

// deque : double-ended queue

// deque <저장하고자 하는 타입> 컨테이너명
deque <int> que;//FIFO queue 구현
deque <int> stk;//LIFO stack 구현

// 주로 사용할 method
// front() - 가장 앞 데이터 얻기 (리턴 -> 컨테이터에 저장한 data reference)
// back() - 가장 마지막 데이터 얻기

// push_front(데이터) - 앞쪽에 데이터 넣기
// push_back(데이터) - 뒤쪽에 데이터 넣기

// pop_front() - 가장 앞 데이터 꺼내기 (리턴 없음)
// pop_back() - 가장 뒤 데이터 꺼내기 (리턴 없음)

int main(void) {

	//FIFO queue 구현
	que.clear();//초기화
	for (int i = 1; i <= 5; i++) {
		que.push_back(i);
	}
	cout << "저장된 개수 = " << que.size() << endl;

	while (!que.empty()) {
		cout << que.front() << endl;//제일 먼저 저장된 값 읽기
		que.pop_front();//제일 먼저 저장된 값 제거
	}


	//LIFO stack 구현
	stk.clear();//초기화
	for (int i = 1; i <= 5; i++) {
		stk.push_back(i);
	}
	cout << "저장된 개수 = " << stk.size() << endl;

	while (!stk.empty()) {
		cout << stk.back() << endl;//제일 나중에 저장된 값 읽기
		stk.pop_back();//제일 나중에 저장된 값 제거
	}

	return 0;
}
