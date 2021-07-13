#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

const int INT_INF = 2147483647;
const int INF = 987654321;
const int MAX_N = 1e+5 + 1;
const int MOD = 1e5;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int graveYard[31][31] = { 0, };

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
vector<pi> edges[910];
vector<pi> ghost(910);
int dp[910] = { 0, };

void makeGraph(int& w, int& h) {
	for (int cx = 0; cx < w; ++cx) for (int cy = 0; cy < h; ++cy) {
		if (cx == w - 1 && cy == h - 1) continue;
		if (graveYard[cx][cy] == -1) continue;

		int curNum = cy * w + cx;

		// ±Í½Å ±¸¸Û ÀÔ±¸
		if (!edges[curNum].empty()) continue;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;

			int nextNum = ny * w + nx;
			if (graveYard[nx][ny] != -1) {
				//cout << cx << ' ' << cy << "\tto\t" << nx << ' ' << ny << endl;
				edges[curNum].push_back({ nextNum, 1 });
			}
		}
	}
}

void bellman_ford(int& w, int& h) {
	for (int i = 0; i < w * h; ++i) dp[i] = INF;
	dp[0] = 0;

	for (int i = 0; i < w * h - 1; ++i) {
		for (int cur = 0; cur < w * h; ++cur) {
			if (dp[cur] == INF) continue;
			for (auto next : edges[cur]) {
				if (dp[next.first] > dp[cur] + next.second) {
					dp[next.first] = dp[cur] + next.second;
				}
			}
		}
	}


	for (int cur = 0; cur < w * h; ++cur) {
		if (dp[cur] == INF) continue;
		for (auto next : edges[cur]) {
			if (dp[next.first] > dp[cur] + next.second) {
				cout << "Never\n";
				return;
			}
		}
	}

	if (dp[w * h - 1] == INF) cout << "Impossible\n";
	else cout << dp[w * h - 1] << '\n';


	return;


}

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	while (true) {
		int w, h, g, e, x, y, value;
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		memset(graveYard, 0, sizeof(graveYard));
		for (int i = 0; i < w * h; ++i) edges[i].clear();

		cin >> g;
		for (int i = 0; i < g; ++i) {
			cin >> x >> y;
			graveYard[x][y] = -1;
		}
		cin >> e;
		for (int i = 1; i <= e; ++i) {
			cin >> x >> y;
			int from = y * w + x;
			cin >> x >> y >> value;
			edges[from].push_back({ y * w + x, value });
		}

		makeGraph(w, h);

		bellman_ford(w, h);

	}

	return 0;
}