// Q2133 Ÿ�� ä���

// DP��. ���� �ȴ�. 
// ã�Ҵ�. ��Ģ��. �ٵ� �� Ʋ���� �ɱ�.
// 
// ��.. ã�Ҵ�..
// ¦����ȣ�� �� ������ ���� ã�Ƴ� ��Ģ �ܿ� �Ѱ��� ���̽��� special�ϰ� �߰��ȴ�. �׳� �ϳ��� �� ���������Ѵ�.

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