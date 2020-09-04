// Q2133 타일 채우기

// DP다. 나도 안다. 
// 찾았다. 규칙을. 근데 왜 틀리는 걸까.
// 
// 와.. 찾았다..
// 짝수번호가 될 때마다 내가 찾아낸 규칙 외에 한개의 케이스가 special하게 추가된다. 그냥 하나가 더 더해져야한다.

#include <iostream>
using namespace std;
int a[31] = { 0, };
int main() {
	int n, tmp;
	cin >> n;
	a[0] = 1; a[2] = 3;
	for (int i = 4; i <= n; i += 2) {
		for (int j = 2; j <= i; j += 2) {
			tmp = j == 2 ? 3 : 2;
			a[i] += tmp * a[i - j];
		}
	}
	cout << a[n];
	return 0;
}