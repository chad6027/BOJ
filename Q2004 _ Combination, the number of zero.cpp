// 2004 조합 0의 개수

// 1676번에서 썼던 방법을 응용했다.
//          n!
// nCr = ---------
//        r!(n-r)!
// 임을 알고있고 1676번을 풀어봤다면 쉽게 풀리는 문제.
// 분자 분모의 0의 개수를 각각 min(2의 개수, 5의 개수) 로 생각하고만 풀면 
// 분자의 0의 개수 = 2의 개수, 분모의 0의 개수 = 5의 개수와 같은 계산하면 안되는 경우가 나오는 것에 유의.
// 따라서, 내가 선택한 방법은 분자의 2의 개수와 5의 개수 모두 분모의 것보다 클 때만 0이 생기기 때문에
// 2의 개수나 5의 개수가 분모가 더 큰 경우에는 0을 출력
// 그렇지 않다면 각각 분자에서 분모를 뺀 값에서 최솟값을 출력.

// n, m의 범위가 20억이다보니 이 방법으로는 0ms가 나올 수 없을 줄 알았는데... 나와버렸다
// 생각해보니 n, r, n-r 이 세개의 수만 갖고 노는 코드이다 보니 빠를 수 밖에 없긴하다.


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