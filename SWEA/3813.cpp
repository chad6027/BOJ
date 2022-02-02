#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
const int INF = 987654321;
int n, k;
int MIN_WEAR_LEVEL;
int MAX_WEAR_LEVEL;
int wear[200001];
int block[200001];

bool verify(int val) {

	int index = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (wear[i] <= val) cnt++;
		else cnt = 0;

		if (cnt == block[index]) {
			index++;
			cnt = 0;

			if (index == k) return true;
		}
	}
	return false;
}

int binarySearch() {
	int left = MIN_WEAR_LEVEL - 1, right = MAX_WEAR_LEVEL + 1;
	int ret = 0;
	while (left < right) {
		int mid = (left + right) / 2;

		if (verify(mid)) {
			right = mid;
			ret = right;
		}
		else left = mid + 1;
	}
	return ret;
}

int main(int argc, char** argv)
{
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{

		cin >> n >> k;
		MAX_WEAR_LEVEL = 0;
		MIN_WEAR_LEVEL = INF;
		for (int i = 0; i < n; ++i) {
			cin >> wear[i];
			MAX_WEAR_LEVEL = max(MAX_WEAR_LEVEL, wear[i]);
			MIN_WEAR_LEVEL = min(MIN_WEAR_LEVEL, wear[i]);
		}
		for (int i = 0; i < k; ++i) cin >> block[i];

		printf("#%d %d\n", test_case, binarySearch());


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}