// Q1167 _ Ʈ���� ����

// ����ִ� �����̴�.
// �ƹ� �� ��忡�� �����Ͽ� ���� �� ��带 ���Ͽ�, �� ��忡�� ���� �� ��带 ���ϸ� �Ǵ� �����̴�.
// �� �̰� ���� �ǳĸ� Ʈ���̱� ������ ������ �Ǵ� �� �� ������ ��ΰ� �� �ϳ� �����Ѵٴ� ����� ����ϸ鼭 �ϳ��� ���� ����.
//	 	1
//		|
// 2 -	3  - 4  -  5
// 2 ���� 5������ �� Ʈ���� �����̶�� ��������.
// 1 ���� ���� �� ��带 ã���� 5�� ������, 5���� ���� �� ��带 ã���� 2�� ���´�.
// 2 ���� 5�� ���� ��� ���� �ִ� � ������ DFS�� ��ȸ�� �ϸ� ���� �� ���� 2 or 5�� ���´�.
// ���� ������ �Ǵ� ��� ���� �ִ� ������ DFS�� ��ȸ�� �ϵ�, ��� ���� ���� �ʴ� ��忡�� ��ȸ�� �ϵ� 
// ������ �Ǵ� �� ��� �� �ϳ��� ã�� �� �ִ�.
// �� ��带 ã�Ƽ� ���� �� ��带 ã���� �ٷ� ���� �ȴ�.

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 2147483647;
const int MAX_N = 1e5 + 1;
const int MOD = 1e+9;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

bool visited[MAX_N] = { 0, };
int dp[MAX_N] = { 0, };

vector<pair<int, int>> edges[MAX_N];

int far_node = 0;
int max_sum = 0;

void DFS(int cur, int sum) {

	dp[cur] = sum;
	if (max_sum < sum) {
		max_sum = sum;
		far_node = cur;
	}


	for (auto& next : edges[cur]) {
		if (dp[next.first] == -1) {
			DFS(next.first, sum + next.second);
		}
	}

}

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	memset(dp, -1, sizeof(dp));

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int from, to, w;
		cin >> from;
		while (true) {
			cin >> to;
			if (to == -1) break;
			cin >> w;
			edges[from].push_back({ to, w });
		}
	}


	DFS(1, 0);

	memset(dp, -1, sizeof(dp));

	DFS(far_node, 0);

	cout << max_sum;

	return 0;
}