// Q2156 포도주 시음회

// DP로 풀어야한다는건 문제를 접하자마자 직감했다.
// 그 후로 3시간이 지났다. 난 여전히 점화식을 세우고 있었다.
// 그러다 괜찮은 점화식을 하나 세웠는데 내 생각에는 완벽히 돌아가는 점화식이었고 제출해보니 그대로 오답.
// 반례를 찾아보려 해도 딱히 없어보였다. 결국 또 구글님의 힘을 빌렸고... n번째를 선택안하는 경우의 수도 있다는걸 알아버렸다.
// 
// d[n]을 구할 때, 생각해야 될 것은 두가지
// n-1을 선택하는 경우, n-2을 선택할 수 없다. ==> d[n-3] + a[n-1] + a[n]
// n-1을 선택하지 않는 경우, n-2만 선택 ==> d[n-1] + a[n]
// 라고 생각했으나 n을 선택하지 않는 경우도 존재.
// 따라서 d[n] = max(d[n], d[n-1]) 도 생각해줘야한다.

#include <iostream>
#include <algorithm>
using namespace std;
int a[10001];
int d[10001] = { 0, };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	d[1] = a[1];
	d[2] = a[1] + a[2];
	for (int i = 3; i <= n; i++) {
		d[i] = max(d[i - 3] + a[i - 1] + a[i], d[i - 2] + a[i]);
		d[i] = max(d[i - 1], d[i]);
		ans = max(ans, d[i]);
	}
	if (n <= 2) {
		cout << d[n];
	}
	else
		cout << ans;

	return 0;
}