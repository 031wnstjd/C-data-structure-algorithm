#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <unordered_map>

#define MAX_N (50000)

using namespace std;

struct COW {
	long long id;
	int pos;
};

deque<COW> queue;

int N, pos;
long long id;

COW cow[MAX_N];
unordered_map<long long, int> check_list; // id가 10억 이하이므로 hash-table을 활용
int cnt;

bool compare(COW &a, COW &b) {
	return a.pos < b.pos;
}

void Input_Data(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cow[i].pos >> cow[i].id;
		check_list.insert({ cow[i].id, 1 });
	}
	cnt = check_list.size();
}

long long Solve(void) {
	check_list.clear();

	sort(cow, cow + N, compare);
	long long min_size = 1000000001;
	for (int i = 0; i < N; i++) {
		queue.push_back(cow[i]);

		auto iter = check_list.find(cow[i].id);
		if (iter != check_list.end()) { // 기존에 존재하는 소라면 카운트
			iter->second += 1;
		}
		else { // 기존에 존재하는 소가 아니라면 카운트 1로 초기화
			check_list.insert({ cow[i].id, 1 });
		}

		while (check_list.size() == cnt) { // 모든 품종이 포함되면 min_size 갱신
			int cur_size = cow[i].pos - queue.front().pos;
			min_size = min_size > cur_size ? cur_size : min_size;

			COW tmp = queue.front();
			auto iter = check_list.find(tmp.id);
			iter->second -= 1; // 개수 1 차감
			if (iter->second == 0) check_list.erase(tmp.id); // 개수가 0이되면 리스트에서 삭제
			queue.pop_front();
		}
	}

	return min_size;
}

int main(void) {

	Input_Data();

	cout << Solve() << '\n';

	return 0;
}
