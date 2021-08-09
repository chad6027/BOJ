#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <string.h>
#include <string>
#include <algorithm>
#include <utility>
#include <iterator>
#define ll long long
#define MAX 10001
using namespace std;

class Edge {
public:
	int s, e, w;
	Edge(int s, int e, int w) :s(s), e(e), w(w) {}
	bool operator < (const Edge& b) const {
		return this->w < b.w;
	}
}; vector<Edge> edges;

int cap[10001];

int find(int x) {
	if (x == cap[x])
		return x;
	else
		return cap[x] = find(cap[x]); // ��� ����
}

bool union_set(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y)
		return false;

	cap[y] = x;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. ���� �������� ����
	// 2. ����Ŭ Ȯ��
	// 3. ���� �ֱ�

	// union-find �˰��� ���

	int V, E;
	cin >> V >> E;
	for (int i = 0; i <= V; i++) cap[i] = i;

	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		edges.emplace_back(A, B, C);
	}
	sort(edges.begin(), edges.end());
	int cnt = 0;
	int ans = 0;
	for (auto edge : edges) {
		int s = edge.s;
		int e = edge.e;
		int w = edge.w;

		if (union_set(s, e)) {
			cnt++;
			ans += w;
		}

		if (cnt == V - 1)
			break;
	}
	cout << ans << '\n';

	return 0;
}
