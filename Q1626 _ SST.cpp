// Q1626 _ 두 번째로 작은 스패닝 트리
// 처음 시도해보는 다이아 문제다.. 굉장히 어렵다..
// WA상태이기 때문에 문제점이 무엇인지 찾아볼 겸 깃허브에 올린다.

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = 2147483647;
const int MAX = 5 * 1e4 + 1;
const int MOD = 1e9 + 3;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int anc[MAX][20] = { 0, };
int maxCost[MAX][20] = { 0, };
int depth[MAX] = { 0, };
int maxLevel;
vector<pair<pair<int, int>, int>> edges;
vector<int> MSTEdge;
vector<pair<int, int>> tree[MAX];

int findRoot(int cur) {
	if (cur == anc[cur][0]) return cur;
	else return anc[cur][0] = findRoot(anc[cur][0]);
}

void initTree(int cur, int parent, int cost) {
	depth[cur] = depth[parent] + 1;

	anc[cur][0] = parent;
	maxCost[cur][0] = cost;
	for (int i = 1; i <= maxLevel; ++i) {
		anc[cur][i] = anc[anc[cur][i - 1]][i - 1];
	}

	for (auto& next : tree[cur]) {
		if (next.first == parent) continue;
		initTree(next.first, cur, edges[next.second].second);
	}
}

void fillMaxCost(int& n) {
	for (int up = 1; up <= maxLevel; ++up) {
		for (int cur = 1; cur <= n; ++cur) {
			int prev = anc[cur][up - 1];
			maxCost[cur][up] = max(maxCost[cur][up - 1], maxCost[prev][up - 1]);
		}
	}
}

int findCost(int a, int b) {
	int cost = -1;
	if (depth[a] != depth[b]) {
		if (depth[a] > depth[b]) swap(a, b);

		for (int i = maxLevel; i >= 0; --i) {
			if (depth[a] <= depth[anc[b][i]]) cost = max(cost, maxCost[b][i]), b = anc[b][i];
		}
	}

	int LCA = a;

	if (a != b) {
		for (int i = maxLevel; i >= 0; --i) {
			if (anc[a][i] != anc[b][i]) {
				cost = max({ cost, maxCost[a][i], maxCost[b][i] });
				a = anc[a][i];
				b = anc[b][i];
			}
			LCA = anc[a][i];
		}
	}

	if (LCA != a) cost = max({ cost, maxCost[a][0], maxCost[b][0] });

	return cost;
}

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, originCost = 0;
	cin >> n >> m;
	for (int i = 0; i <= n; ++i) anc[i][0] = i;
	edges.resize(m);
	for (int i = 0; i < m; ++i) {
		int from, to, weight;
		cin >> from >> to >> weight;
		edges[i] = { {from, to}, weight };
	}

	sort(edges.begin(), edges.end(), [](const pair<pair<int, int>, int>& p1, const pair<pair<int, int>, int>& p2) ->bool {
		return p1.second < p2.second;
	});

	for (int i = 0; i < m; ++i) {
		pair<pair<int, int>, int>& cur = edges[i];
		int rootA = findRoot(cur.first.first);
		int rootB = findRoot(cur.first.second);
		if (rootA == rootB) continue;
		anc[rootA][0] = min(rootA, rootB);
		anc[rootB][0] = min(rootA, rootB);

		originCost += cur.second;
		MSTEdge.push_back(i);
		tree[cur.first.first].push_back({ cur.first.second, i });
		tree[cur.first.second].push_back({ cur.first.first, i });
	}
	// has not found minimum spanning tree
	if (MSTEdge.size() != n - 1) {
		cout << -1;
		return 0;
	}

	// make Tree
	depth[0] = -1;
	maxLevel = (int)floor(log2(MAX));
	initTree(1, 0, 0);

	// fill maxCost
	fillMaxCost(n);

	// add One Edge
	int dif = INF;
	for (int i = 0; i < m; ++i) {
		pair<pair<int, int>, int>& cur = edges[i];
		int from = cur.first.first;
		int to = cur.first.second;

		int cost = findCost(from, to);

		if (cur.second - cost > 0) {
			dif = min(dif, cur.second - cost);
		}
	}

	if (dif == INF) cout << -1;
	else cout << originCost + dif;

	return 0;
}