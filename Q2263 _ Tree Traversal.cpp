// Q2263 _ 트리의 순회
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 2147483647;
const int MAX_N = 1e5 + 1;
const int MOD = 1e+9;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int pos[MAX_N];
int inOrder[MAX_N];
int postOrder[MAX_N];

void getTree(int start, int end) {

	if (start > end) return;
	else if (start == end) {
		printf("%d ", postOrder[start]);
		return;
	}

	printf("%d ", postOrder[end]);

	int mid = start;
	for (mid; mid < end; ++mid) {
		if (pos[postOrder[mid]] > pos[postOrder[end]]) break;
	}

	getTree(start, mid - 1);
	getTree(mid, end - 1);

	return;
}


int main()
{
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, tmp;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> inOrder[i];
		pos[inOrder[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> postOrder[i];
	}

	getTree(1, n);

	return 0;
}