#include <iostream>
#include <math.h>
using namespace std;
#define ll long long
bool findnono[1000001] = { 0, };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ll a, b, sqrt_b;
	cin >> a >> b;
	ll ans = 0;
	sqrt_b = sqrt(b);
	
	for (long long i = 2; i <= sqrt_b; i++) {
		ll tmp = i * i;
		ll MIN = a;
		if (a % tmp != 0) {
			MIN = (a / tmp + 1) * tmp;
		}

		for (MIN; MIN <= b; MIN += tmp) {
			if (!findnono[MIN - a]) {
				findnono[MIN - a] = true;
				ans++;
			}
		}
	}
	
	
	cout << b - a + 1 - ans;

	return 0;
}