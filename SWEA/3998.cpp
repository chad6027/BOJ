// SWEA 3998 Inversion Counting
// Merge Sort
#include<iostream>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
const int INF = 987654321;
const int MOD = 1000000007;
const int MAX_N = 1e5 + 2;

int arr[100001];
int tmp[100001];
long long ans = 0;

void merge(int start, int mid, int end) {
	int first = start, second = mid + 1, cur = start;


	while (first <= mid && second <= end) {
		if (arr[first] < arr[second]) tmp[cur++] = arr[first++];
		else if (arr[first] > arr[second]) {
			ans += ((long long)mid - (long long)first + 1);
			tmp[cur++] = arr[second++];
		}
	}

	while (first <= mid) { tmp[cur++] = arr[first++]; }
	while (second <= end) { tmp[cur++] = arr[second++]; }

	for (int i = start; i <= end; i++) arr[i] = tmp[i];


}

void mergeSort(int start, int end) {
	int mid = (start + end) / 2;

	if (start < end) {
		mergeSort(start, mid);
		mergeSort(mid + 1, end);
		merge(start, mid, end);
	}
}


int main(int argc, char** argv)
{
	ios::ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{

		int n, num;
		cin >> n;

		ans = 0;
		for (int i = 1; i <= n; ++i) cin >> arr[i];

		mergeSort(1, n);

		printf("#%d %lld\n", test_case, ans);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}