// Q15686 _ 치킨 게임

// 골드 5짜리 문제치고 쉬운 문제다.
// 완전 탐색으로 M개의 치킨집을 고르고 최솟값을 구하면 된다.

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = 2147483647;
const int MAX_N = 10e+4 + 1;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
int city[51][51] = { 0, };
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

bool visited[14] = { 0, };

int calDist(pair<int, int>& p1, pair<int, int>& p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int DFS(int cur, int cnt) {
	if (cnt == m) {
		int sum = 0;

		for (pair<int, int> p : house) {
			int short_dist = INF;
			for (int i = 0; i < 14; ++i) {
				if (visited[i]) short_dist = min(short_dist, calDist(chicken[i], p));
			}

			sum += short_dist;
		}
		return sum;
	}


	int ans = INF;
	for (int next = cur; next < chicken.size(); ++next) {
		if (!visited[next]) {
			visited[next] = true;
			ans = min(ans, DFS(next, cnt + 1));
			visited[next] = false;
		}
	}
	return ans;
}


int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		cin >> city[i][j];
		if (city[i][j] == 1) house.push_back({ i,j });
		else if (city[i][j] == 2) chicken.push_back({ i,j });
	}

	cout << DFS(0, 0);

	return 0;
}