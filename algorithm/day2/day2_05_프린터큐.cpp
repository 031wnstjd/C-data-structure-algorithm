#include <iostream>
#include <deque>

using namespace std;

#define MAX_N (100)

struct Doc {
	int p, loc;
};

int N, M;
int cnt_priority[10]; 
deque<Doc> que;

void Init(void) {
	que.clear();
	for (int i=1; i<10; i++) {
		cnt_priority[i] = 0;
	}
}

void Input_Data(void) {
	cin >> N >> M;
	for (int i=0; i< N; i++) {
		Doc doc;
		doc.loc = i;
		cin >> doc.p;
		cnt_priority[doc.p]++;
		que.push_back(doc);
	}
}

void Solve() {
	int cnt_print = 0;
	Doc doc;
	while(!que.empty()) {
		bool is_greater = false;
		doc = que.front();
		for(int i=doc.p+1; i<10; i++) {
			if(cnt_priority[i] > 0) {
				que.push_back(doc);
				is_greater = true;
				break;
			}
		}
		if(!is_greater) { // 현재 원소가 우선순위가 가장 높다면 
			cnt_priority[doc.p]--;
			cnt_print++; // 출력됨 
			if(doc.loc == M) break;
		}
		que.pop_front();
	}
	cout << cnt_print << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int TC;
	cin >> TC;
	for(int i=1; i<=TC; i++) {
		Init();
		Input_Data();
		
		Solve();	
	}
	return 0;
}
