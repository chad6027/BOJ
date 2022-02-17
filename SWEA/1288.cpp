// swea1288 새로운 불면증 치료법
#include<iostream>
#include<string.h>
#include <string>
using namespace std;
bool check[10];

bool isAllChecked() {
	for (int i = 0; i < 10; ++i) if (!check[i]) return false;
	return true;
}

void solve(int t) {
	long long n, ans = 0;
	cin >> n;

	while (++ans) {
		long long tmp = ans * n;
		while (tmp / 10LL) {
			check[tmp % 10LL] = true;
			tmp /= 10LL;
		}
		check[tmp % 10LL] = true;

		if (isAllChecked()) {
			printf("#%d %lld\n", t, ans * n);
			return;
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(check, 0, sizeof(check));

		solve(test_case);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}