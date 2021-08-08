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

int country[1001];


int find(int x) {
	if (x == country[x])
		return x;
	else
		return country[x] = find(country[x]); // 경로 압축
}

bool union_set(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y)
		return false;

	country[y] = x;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. 간선 오름차순 정렬
	// 2. 사이클 확인
	// 3. 집합 넣기

	// union-find 알고리즘 사용
	int T;
	cin >> T;
	while (T--)
	{
		edges.clear();
		int V, E;
		cin >> V >> E;
		for (int i = 0; i <= V; i++) country[i] = i;

		for (int i = 0; i < E; i++) {
			int A, B;
			cin >> A >> B;
			edges.emplace_back(A, B, 0);
		}
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
		cout << cnt << '\n';
	}

	return 0;
}
