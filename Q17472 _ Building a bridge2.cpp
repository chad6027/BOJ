// Q17472 다리 만들기2

// DFS로 섬을 표시하고 최소신장트리를 이용하여 가장 짧은 다리들을 먼저 만드는 문제였다.
// 가장 중요했던 부분은 마지막에 모든 섬이 연결되어있는지 확인하는 부분과
// 섬이 1   2   3 이런식으로 있으면 1에서 스타트했을 때 2를 확인하면 바로 멈춰야하는 부분이었다.


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 2147483647;
const int MAX_N = 1e4 + 1;
const int MOD = 1e+9;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
int board[11][11];
int land[11][11] = { 0, };
bool visited[11][11] = { 0, };
int dist[7][7] = { 0, };
int anc[7] = { 0, };

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
void DFS(int cx, int cy, int num) {
	visited[cx][cy] = true;
	land[cx][cy] = num;
	for (int i = 0; i < 4; ++i) {
		int nx = cx + dx[i];
		int ny = cy + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

		if (!visited[nx][ny] && board[nx][ny] == 1) DFS(nx, ny, num);
	}
}

int find_root(int cur) {
	if (cur == anc[cur]) return cur;
	else return anc[cur] = find_root(anc[cur]);
}

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	int island = 0;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> board[i][j];
	// DFS로 섬 표시
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (!visited[i][j] && board[i][j] == 1) {
			DFS(i, j, ++island);
		}
	}

	// 각 섬으로부터 직선 거리로 가장 가까운 거리에 있는 섬 찾기
	for (int i = 1; i <= island; ++i) for (int j = 1; j <= island; ++j) dist[i][j] = INF;

	for (int cx = 0; cx < n; ++cx) for (int cy = 0; cy < m; ++cy) {
		if (land[cx][cy]) {
			for (int i = 0; i < 4; ++i) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (land[cx][cy] == land[nx][ny]) continue; 

				while (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if (land[nx][ny] == 0) {
						nx += dx[i];
						ny += dy[i];
					}
					else if (land[nx][ny]) {

						if (land[cx][cy] != land[nx][ny]) { // 다른 섬일때만 거리 계산
							int d = abs(cx - nx) + abs(cy - ny) - 1;
							int MIN = min(land[cx][cy], land[nx][ny]);
							int MAX = max(land[cx][cy], land[nx][ny]);

							if (d > 1) dist[MIN][MAX] = min(dist[MIN][MAX], d);
						}

						break;
					}
				}
			}
		}
	}

	vector<pair<int, pair<int, int>>> vec;
	for (int i = 1; i <= island; ++i) for (int j = i + 1; j <= island; ++j) if (dist[i][j] != INF) vec.push_back({ dist[i][j], {i , j} });
	sort(vec.begin(), vec.end());

	for (int i = 0; i < 7; ++i) anc[i] = i;

	int ans = 0;
	// Kruskal Algorithm
	for (int i = 0; i < vec.size(); ++i) {

		int root_a = find_root(vec[i].second.first);
		int root_b = find_root(vec[i].second.second);

		if (root_a == root_b) continue;

		anc[root_a] = min(root_a, root_b);
		anc[root_b] = min(root_a, root_b);

		ans += vec[i].first;
	}
	// 모든 섬이 연결되어있는지 확인
	bool connected = true;
	for (int i = 1; i <= island; ++i) if (find_root(i) != 1) connected = false;

	if (connected) cout << ans;
	else cout << -1;

	return 0;
}