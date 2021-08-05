//Q3273 두 수의 합
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 2147483647;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll num[100001] = { 0, };

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];
	cin >> x;
	sort(num, num + n);
	int ans = 0;
	int start = 0, end = n - 1;
	while (start < end) {
		int sum = num[start] + num[end];
		if (sum < x) start++;
		else if (sum > x) end--;
		else {
			ans++;
			end--;
		}
	}

	cout << ans;


	return 0;
}