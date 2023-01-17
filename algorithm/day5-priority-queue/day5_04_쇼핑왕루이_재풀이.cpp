/**
  백준 5896 효율적으로 소 사기
*/

#include <iostream>
#include <queue>

using namespace std;

#define MAX_N (50000)

struct PRICE {
	int normal;
	int coupon;
	bool sold;
};

struct COMP1 { // normal 기준 오름차순 정렬 
	bool operator()(PRICE* a, PRICE* b) {
		return a->normal > b->normal;
	}
};

struct COMP2 { // coupon 기준 오름차순 정렬 
	bool operator()(PRICE* a, PRICE* b) {
		return a->coupon > b->coupon;
	}
};

struct COMP3 { // benefit 기준 오름차순 정렬 
	bool operator()(int a, int b) {
		return a > b;
	}
};


priority_queue<PRICE*, vector<PRICE*>, COMP1> pq_normal;
priority_queue<PRICE*, vector<PRICE*>, COMP2> pq_coupon;
priority_queue<int, vector<int>, COMP3> pq_benefit;

int N; // 제품 개수 
int K; // 쿠폰 개수 
long long M; // 루이가 갖고 있는 돈 

PRICE price[MAX_N + 10];

void Input_Data(void) {
	cin >> N >> K >> M;
	for (int i = 0; i < N; i++) {
		cin >> price[i].normal >> price[i].coupon;
		pq_normal.push(&price[i]);
		pq_coupon.push(&price[i]);
	}
}

int Solve() {
	int cnt = 0;

	// 1. 쿠폰 소진될 때까지 반복
	while (!pq_coupon.empty() && K > 0) {
		PRICE* price_coupon = pq_coupon.top();
		if (M < price_coupon->coupon) break; // 최소 쿠폰가가 남은 M보다 크면 while문 탈출
		
		K--;
		M -= price_coupon->coupon;
		price_coupon->sold = true;
		pq_coupon.pop();
		pq_benefit.push(price_coupon->normal - price_coupon->coupon); // 할인액 push
		cnt++;
	}
	
	// 2. 최소 원가 담기 or 쿠폰 교환 (결과 비교)
	while (M > 0) {
		while (!pq_normal.empty() && pq_normal.top()->sold) pq_normal.pop();
		PRICE* price_normal = pq_normal.empty() ? (PRICE*)0 : pq_normal.top();
		int min_benefit = pq_benefit.empty() ? 0 : pq_benefit.top();
	
		if (price_normal == (PRICE*)0) break; //  비었으면 break

		int a = M - price_normal->normal; // 최소 원가 고려시
		int b = M - min_benefit - price_normal->coupon; // 쿠폰 교환시
		
		price_normal->sold = true; // 판매됨

		if (a < 0 && b < 0) {
			continue; // 둘 다 결과값이 음수면 continue
		}

		cnt++;

		if (a >= b) {
			M = a;
		}
		else {
			M = b;
			pq_benefit.pop();
			pq_benefit.push(price_normal->normal - price_normal->coupon);
		}
	}

	return cnt;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input_Data();

	cout << Solve() << '\n';

	return 0;
}
