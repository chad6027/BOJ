#include <iostream>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
pair<int, int> p[20];
int a[20];

//코드가 중구난방. 깔끔한 정리 요구
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T, N;
	cin >> T;

	while (T--) {
		pair<int, int> total;
		pair<int, int> p_ans;
		pair<int, int> left, right;

		double ans = 9876543210;
		memset(p, 0, sizeof(p));

		int cnt = 1;
		total.first = 0, total.second = 0 , left.first = 0, left.second = 0;

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> p[i].first >> p[i].second;
			total.first += p[i].first;
			total.second += p[i].second;
		}


		for (int i = 0; i < 20; i++) {
			a[i] = i + 1;
		}


		for (int i = N; i > N / 2; i--) {
			cnt *= i;
			cnt /= (N - i + 1);
			left.first += p[i - 1].first;
			left.second += p[i - 1].second;
		}
		cnt = cnt / 2 - 1; // 나올 수 있는 경우의 수
		
		
		
		ans = sqrt(pow(total.first - 2 * left.first, 2) + pow(total.second - 2 * left.second, 2));

		int inc = N / 2 - 1;

		while (cnt--) {
			//--------------------------- nCr 조합으로 나올 수 있는 경우의 수 뽑아주기
			if (a[inc] <= N / 2 + inc){
				a[inc]++;
			}
			else {
				while (a[--inc] > N / 2 + inc) {
					
				}
				inc++;
				a[inc - 1]++;
				for (inc; inc < N / 2; inc++) {
					a[inc] = a[inc - 1] + 1;
				}
				inc--;
			}
			//-----------------------------

			// A + B = T
			// B - A = ?
			// B = T - A ==> B - A = T - 2A
			left.first = 0, left.second = 0;
			for (int i = 0; i < N / 2; i++) {
				left.first += p[a[i] - 1].first;
				left.second += p[a[i] - 1].second;
			}
			p_ans.first = total.first -  2 * left.first;
			p_ans.second = total.second - 2 * left.second;

			ans = min(ans, sqrt(pow(p_ans.first, 2) + pow(p_ans.second, 2)));
		}


		cout << fixed;
		cout.precision(12);
		cout << ans << '\n';
	}

	return 0;
}