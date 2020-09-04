// 2004 ���� 0�� ����

// 1676������ ��� ����� �����ߴ�.
//          n!
// nCr = ---------
//        r!(n-r)!
// ���� �˰��ְ� 1676���� Ǯ��ôٸ� ���� Ǯ���� ����.
// ���� �и��� 0�� ������ ���� min(2�� ����, 5�� ����) �� �����ϰ� Ǯ�� 
// ������ 0�� ���� = 2�� ����, �и��� 0�� ���� = 5�� ������ ���� ����ϸ� �ȵǴ� ��찡 ������ �Ϳ� ����.
// ����, ���� ������ ����� ������ 2�� ������ 5�� ���� ��� �и��� �ͺ��� Ŭ ���� 0�� ����� ������
// 2�� ������ 5�� ������ �и� �� ū ��쿡�� 0�� ���
// �׷��� �ʴٸ� ���� ���ڿ��� �и� �� ������ �ּڰ��� ���.

// n, m�� ������ 20���̴ٺ��� �� ������δ� 0ms�� ���� �� ���� �� �˾Ҵµ�... ���͹��ȴ�
// �����غ��� n, r, n-r �� ������ ���� ���� ��� �ڵ��̴� ���� ���� �� �ۿ� �����ϴ�.


#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<long long, long long> zeros(long long& tmp) {

	long long t = 0, f = 0;

	for (long long i = 2; i <= tmp; i *= 2) {
		t += tmp / i;
	}

	for (long long i = 5; i <= tmp; i *= 5) {
		f += tmp / i;
	}

	return pair<long long, long long > (t, f);
}


int main() {
	pair<long long, long long > p1, p2, p3;
	long long n = 0, m = 0;
	cin >> n >> m;	
	p1 = zeros(n);
	p2 = zeros(m);
	n = n - m;
	p3 = zeros(n);
	p2.first += p3.first;
	p2.second += p3.second;

	if (p1.first <= p2.first || p1.second <= p2.second) {
		cout << 0;
	}
	else {
		cout << min(p1.first - p2.first, p1.second - p2.second);
	}


	return 0;
}