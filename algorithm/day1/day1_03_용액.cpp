/* 정올_2300_용액 */

/**
	[아이디어]
	"정렬된" 배열에서 "두 원소의 합"이 "특정 값(가령, M)"일 때가(혹은 가까울 때가)
	언제인지 찾으려면 투포인터(Tow Pointers) 알고리즘 사용 
*/


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
