#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define MAX_N (50000)

int N;

struct COW {
	int pos;
	int id;
};

COW cow[MAX_N];
unordered_map<int, int> cnt_ht;

bool comp(COW &a, COW &b) {
	return a.pos < b.pos;
}

void Input_Data(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cow[i].pos >> cow[i].id;
		if (cnt_ht.find(cow[i].id) == cnt_ht.end()) { // 처음 입력되는 품종만 insert
			cnt_ht.insert({ cow[i].id, 0 });
		}
	}
}

int Solve(void) {
	sort(cow, cow + N, comp);
	int min_range = 1000000001;
	int cnt = 0; // 현재 구간에 포함되는 품종 수
	int total = cnt_ht.size();

	// 투포인터 알고리즘
	int e = 0;
	for (int s = 0; s < N; s++) {
		while (e < N && cnt < total) {
			auto it = cnt_ht.find(cow[e].id);
			it->second += 1;
			if (it->second == 1) cnt++; // 현재 구간에 새로 추가되면 cnt++
			e++;
		}

		if (e == N && cnt < total) break;

		// s ~ e-1
		int range = cow[e - 1].pos - cow[s].pos;
		min_range = min_range > range ? range : min_range;
		
		auto it = cnt_ht.find(cow[s].id);
		it->second -= 1;
		if(it->second == 0) cnt--; // 현재 구간에서 빠지면 cnt--
	}

	return min_range;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input_Data();

	cout << Solve() << '\n';
	
	return 0;
}
