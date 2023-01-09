#include <iostream>

using namespace std;

#define MAX_N (100000)

int N;
int num[MAX_N + 1];

void Input_Data() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}
}

void Solve(int &sol_smart, int &sol_fool) { // &를 통해 참조하면 변수 자체를 받을 수 있음
	int s_smart = 0;
	int s_fool = -10000;

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (num[i] > 0) s_smart += num[i]; // 똑똑한 다람쥐는 양수일 때만 합
		sum += num[i];
		if (s_fool < sum) s_fool = sum;
		if (sum < 0) sum = 0; // 구간의 합이 음수면 다음 지점부터 구간을 다시 시작
	}
	if (s_smart == 0) s_smart = s_fool; // 양수일 때가 없으면 멍청한 다람쥐의 결과값(음수 중 최댓값)을 대입

	sol_smart = s_smart;
	sol_fool = s_fool;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input_Data();

	int sol_smart, sol_fool;

	Solve(sol_smart, sol_fool);

	cout << sol_fool << " " << sol_smart << '\n';

	return 0;
}
