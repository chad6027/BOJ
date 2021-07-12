// Q2156 ������ ����ȸ

// DP�� Ǯ����Ѵٴ°� ������ �����ڸ��� �����ߴ�.
// �� �ķ� 3�ð��� ������. �� ������ ��ȭ���� ����� �־���.
// �׷��� ������ ��ȭ���� �ϳ� �����µ� �� �������� �Ϻ��� ���ư��� ��ȭ���̾��� �����غ��� �״�� ����.
// �ݷʸ� ã�ƺ��� �ص� ���� �������. �ᱹ �� ���۴��� ���� ���Ȱ�... n��°�� ���þ��ϴ� ����� ���� �ִٴ°� �˾ƹ��ȴ�.
// 
// d[n]�� ���� ��, �����ؾ� �� ���� �ΰ���
// n-1�� �����ϴ� ���, n-2�� ������ �� ����. ==> d[n-3] + a[n-1] + a[n]
// n-1�� �������� �ʴ� ���, n-2�� ���� ==> d[n-1] + a[n]
// ��� ���������� n�� �������� �ʴ� ��쵵 ����.
// ���� d[n] = max(d[n], d[n-1]) �� ����������Ѵ�.

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