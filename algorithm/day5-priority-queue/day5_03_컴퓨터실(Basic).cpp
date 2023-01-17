#include <iostream>
#include <queue>

#define MAX_N (100000)
#define MAX_Q (100000)
#define MAX_M (300000)

using namespace std;

struct GROUP {
	int s, e;
	int size;
};

struct COMP {
	bool operator()(const GROUP& a, const GROUP& b) {
		if (a.size == b.size) return a.s > b.s;
		else return a.size < b.size;
	}
};

priority_queue<GROUP, vector<GROUP>, COMP> pq;

inline int Get_Size(int s, int e) {
	return e - s + 1;
}

int M; // 컴퓨터 수
int N; // 이미 자리를 잡은 학생의 수
int Q; // 친구의 수
int A[MAX_M + 1];
int B[MAX_Q];

void Input_Data_And_Init(void) {
	cin >> M >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		int size = Get_Size(A[i - 1] + 1, A[i] - 1);
		if (size > 0) {
			pq.push({ A[i - 1] + 1, A[i] - 1, size });
		}
	}
	if (M - A[N] != 0) { // 마지막 컴퓨터 자리에 미리 앉지 않았다면
		pq.push({ A[N] + 1, M, Get_Size(A[N] + 1, M) });
	}
	for (int i = 0; i < Q; i++) {
		cin >> B[i];
	}
}

void Simulation(void) {
	for (int i = N + 1; i <= M; i++) {
		GROUP g = pq.top(); pq.pop();
		A[i] = (g.s + g.e) / 2; // 정해진 Rule대로 자리 배정

		// 쪼개진 왼쪽 그룹 : g.s ~ A[i] - 1
		int size = Get_Size(g.s, A[i] - 1);
		if (size > 0) {
			pq.push({ g.s, A[i] - 1, size });
		}
		
		// 쪼개진 오른쪽 그룹 : A[i] + 1 ~ g.e
		size = Get_Size(A[i] + 1, g.e);
		if (size > 0) {
			pq.push({ A[i] + 1, g.e, size });
		}
	}
}

void Print_Result(void) {
	for (int i = 0; i < Q; i++) {
		cout << A[B[i]] << '\n';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input_Data_And_Init();
	
	Simulation();

	Print_Result();

	return 0;
}
