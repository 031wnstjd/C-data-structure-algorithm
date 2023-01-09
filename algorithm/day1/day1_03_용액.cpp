/* 정올_2300_용액 */

#include <iostream>
using namespace std;


#define MAX_N (100000)

int N;
int solution[MAX_N];

void Input_Data() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> solution[i];
	}
}

void Solve(int &val1, int &val2) {
	int l = 0;
	int r = N - 1;
	int min_sum = 1000000000;

	while (l < r) {
		int sum = solution[l] + solution[r];
		int abs_sum = sum < 0 ? -sum : sum;
		
		if (abs_sum < min_sum) {
			min_sum = abs_sum;
			val1 = solution[l];
			val2 = solution[r];
		}
		if (sum == 0) break;
		if (sum < 0) l++;
		if (sum > 0) r--;
	}

}

int main(void)
{	
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
	
	Input_Data();

	int val1, val2;

	Solve(val1, val2);

	cout << val1 << " " << val2 << '\n';

	return 0;
}
