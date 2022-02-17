// SWEA 동아리실 관리하기
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int MOD = 1000000007;

int dp[1 << 4][10001] = { 0, };
string res;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> res;
		// 1일차
		int part = 1 | (1 << (res[0] - 'A'));
		for (int i = 1; i < (1 << 4); ++i) {
			dp[i][0] = 0;
			if ((i & 1) && (i & (1 << (res[0] - 'A')))) dp[i][0] = 1;
		}

		// 나머지
		for (int i = 1; i < res.size(); ++i) {
			int key = (1 << (res[i] - 'A'));
			for (int part = 1; part < (1 << 4); ++part) {
				dp[part][i] = 0;
				if (part & key) {
					for (int prevPart = 1; prevPart < (1 << 4); ++prevPart) {
						if (prevPart & part) dp[part][i] = (dp[part][i] + dp[prevPart][i - 1]) % MOD;
					}
				}
			}
		}

		int sum = 0;
		for (int i = 0; i < (1 << 4); ++i) sum = (sum + dp[i][res.size() - 1]) % MOD;
		printf("#%d %d\n", test_case, sum);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}