//Q1003 _ 피보나치 함수

// 문제에서 준 재귀함수를 이용하게 되면 시간초과가 나기 때문에
// 점화식을 통해 빠르게 계산
// 문제를 잘못 읽어 39번째까지만 구하게 했다가 오답처리를 몇번 당한지 모르겠다.
// 똑바로 문제를 잘읽어야할 듯.

#include <iostream>
using namespace std;
int fibo[41];
void fibonacci() {
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; i < 41; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
}
int main() {
	int T, n;
	cin >> T;
	fibonacci();
	while (T--) {
		cin >> n;
		if (n == 0) {
			cout << 1 << ' ' << 0 << '\n';
		}
		else if (n == 1) {
			cout << 0 << ' ' << 1 << '\n';
		}
		else {
			cout << fibo[n - 1] << ' ' << fibo[n] << '\n';
		}



	}
	return 0;
}