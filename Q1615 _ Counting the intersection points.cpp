// ���׸�Ʈ Ʈ���� �̿��Ͽ� Ǫ�� ��������.
// ��� ���׸�Ʈ Ʈ���� �̿��ؾ� �Ѵٴ� ����� �˰� Ǯ�̸� �� �����ε�,
// cross�Ǵ� ��Ȳ�� �ʹ� �پ��ؼ� constructive�ϰ� Ǯ�ٰ� ���� �ѹ��̸� ���� ����ȴٴ� �� �˾Ҵ�.
// �׸��� ���� ���׸�Ʈ Ʈ���� query���� update�� �ۼ��� �����ؼ� �ѽð��� �� �Һ�.. 
// �������� �� ���� �� ����.

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