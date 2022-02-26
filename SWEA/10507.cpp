// SWEA 10507 영어 공부
// 투포인터
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

bool isChecked[1000002] = { 0, };
int study[200001];


int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n = 1, p;
		cin >> n >> p;
		for (int i = 0; i < n; ++i) {
			cin >> study[i];
			isChecked[study[i]] = true;
		}
		int ans = p + 1;
		int start = 0, end = 0;
		int available = p;
		int MAXNUM = min((int)1e6 + 1, study[n - 1] + p);
		while (end < MAXNUM) {

			while (end < MAXNUM && (isChecked[end] || available)) {
				if (!isChecked[end]) available--;
				end++;
			}

			ans = max(ans, end - start);

			if (!isChecked[start]) available++;
			start++;
		}

		for (int i = 0; i < n; ++i) isChecked[study[i]] = false;

		printf("#%d %d\n", test_case, ans);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}