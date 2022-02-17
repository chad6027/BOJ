// swea1288 ���ο� �Ҹ��� ġ���
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
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(check, 0, sizeof(check));

		solve(test_case);
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}