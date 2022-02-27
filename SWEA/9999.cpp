//SWEA9999 광고 시간 정하기

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
const long long MOD = (1 << 30) - 1;

int n, L;

int s[100001];
int e[100001];
int sum[100001];

int main(int argc, char** argv)
{
	int test_case;
	int T = 0;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d%d", &L, &n);

		for (register int i = 1; i <= n; ++i) {
			scanf("%d%d", &s[i], &e[i]);
			sum[i] = sum[i - 1] + (e[i] - s[i]);
		}

		int ans = 0;

		for (register int i = 1; i <= n; ++i) {
			int start = s[i];
			int end = start + L;

			if (end > e[n]) ans = max(ans, sum[n] - sum[i - 1]);
			else {
				int target = upper_bound(s + 1, s + n + 1, end) - s - 1;

				int tmp = min(e[target], end) - s[target];

				tmp = target > i ? tmp + sum[target - 1] - sum[i - 1] : tmp;

				ans = max(ans, tmp);
			}
		}

		printf("#%d %d\n", test_case, ans);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}