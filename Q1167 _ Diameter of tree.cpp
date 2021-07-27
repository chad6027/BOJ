// Q1167 _ 트리의 지름

// 재미있는 문제이다.
// 아무 한 노드에서 시작하여 가장 먼 노드를 구하여, 그 노드에서 가장 먼 노드를 구하면 되는 문제이다.
// 왜 이게 답이 되냐면 트리이기 때문에 지름이 되는 두 점 사이의 경로가 단 하나 존재한다는 사실을 기억하면서 하나의 예를 보자.
//	 	1
//		|
// 2 -	3  - 4  -  5
// 2 에서 5까지가 이 트리의 지름이라고 가정하자.
// 1 에서 가장 먼 노드를 찾으면 5가 나오고, 5에서 가장 먼 노드를 찾으면 2가 나온다.
// 2 에서 5로 가는 경로 위에 있는 어떤 점에서 DFS로 순회를 하면 가장 먼 노드로 2 or 5가 나온다.
// 따라서 정답이 되는 경로 위에 있는 점에서 DFS로 순회를 하든, 경로 위에 있지 않는 노드에서 순회를 하든 
// 정답이 되는 두 노드 중 하나를 찾을 수 있다.
// 그 노드를 찾아서 가장 먼 노드를 찾으면 바로 답이 된다.

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