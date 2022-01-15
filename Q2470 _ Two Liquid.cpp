// Q2470 _ µÎ ¿ë¾×

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 2147483647;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll liquid[100001] = { 0, };

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> liquid[i];
	sort(liquid, liquid + n);
	ll first_ans, second_ans;
	ll MIN = INF * 1LL;
	int start = 0, end = n - 1;
	while (start < end) {
		ll sum = liquid[start] + liquid[end];
		if (sum == 0LL) {
			first_ans = liquid[start];
			second_ans = liquid[end];
			break;
		}

		if (abs(MIN) > abs(sum)) {
			first_ans = liquid[start];
			second_ans = liquid[end];
			MIN = sum;
		}
		if (sum > 0) end--;
		else start++;
	}

	cout << first_ans << ' ' << second_ans;


	return 0;
}