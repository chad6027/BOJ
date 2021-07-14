// 세그먼트 트리를 이용하여 푸는 문제였다.
// 사실 세그먼트 트리를 이용해야 한다는 사실을 알고 풀이를 들어간 문제인데,
// cross되는 상황이 너무 다양해서 constructive하게 풀다가 정렬 한방이면 모든게 종료된다는 걸 알았다.
// 그리고 아직 세그먼트 트리의 query문과 update문 작성이 미흡해서 한시간을 또 소비.. 
// 연습만이 살 길인 것 같다.

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

const int INT_INF = 2147483647;
const int INF = 987654321;
const int MAX_N = 2 * 1e3 + 1;
const int MOD = 1e5;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
vector<ll> segTree;
vector<pi> edges;

ll query(int start, int end, int node, int left, int right) {
	if (right < start || end < left) return 0LL;
	if (left <= start && end <= right) return segTree[node];
	int mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}

ll update(int start, int end, int node, int idx, int value) {
	if (idx < start || end < idx) return segTree[node];
	if (start == end) return segTree[node] += value;
	int mid = (start + end) / 2;
	return segTree[node] = (update(start, mid, node * 2, idx, value) + update(mid + 1, end, node * 2 + 1, idx, value));
}

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int h = (int)ceil(log2(n));

	segTree.resize(1 << (h + 1));
	segTree[0] = -1;
	edges.resize(m);
	ll ans = 0;
	for (int i = 0; i < m; ++i) cin >> edges[i].first >> edges[i].second;
	sort(edges.begin(), edges.end());

	for (int i = 0; i < m; ++i) {
		ans += query(1, n, 1, 1, edges[i].second);
		update(1, n, 1, 1, 1);
		update(1, n, 1, edges[i].second, -1);

	}

	cout << ans;

	return 0;
}