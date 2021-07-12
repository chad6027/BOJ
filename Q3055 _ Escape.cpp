// BFS를 이용하여 물을 먼저 이동시킨 후 고슴도치를 BFS로 이동시키면 간단히 풀리는 문제였다.
//
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = 2147483647;
const int MAX = 10e+8;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

char forest[52][52] = { 0, };
int cnt[52][52] = { 0 , };
bool water_visit[52][52] = { 0, };

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void BFS(int& r, int& c, pair<int, int> start, pair<int, int> des) {

	for (int i = 1; i <= r; ++i) for (int j = 1; j <= c; ++j) cnt[i][j] = -1;

	queue<pair<int, int>> que, water_que;
	for (int i = 1; i <= r; ++i) for (int j = 1; j <= c; ++j) if (forest[i][j] == '*') {
		water_visit[i][j] = true;
		water_que.push({ i ,j });
	}

	que.push(start);
	cnt[start.first][start.second] = 0;
	while (!que.empty()) {
		int water_que_sz = water_que.size();
		// 물 채우기
		while (water_que_sz--) {
			int cx = water_que.front().first;
			int cy = water_que.front().second;
			water_que.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx < 1 || nx > r || ny < 1 || ny > c) continue; // 범위 밖
				if (forest[nx][ny] == 'D' || forest[nx][ny] == 'X') continue; // 못 가는 곳
				water_visit[nx][ny] = true;
				water_que.push({ nx, ny });
			}
		}

		int que_sz = que.size();
		// 고슴도치 이동
		while (que_sz--) {
			int cx = que.front().first;
			int cy = que.front().second;
			que.pop();
			if (cx == des.first && cy == des.second) return;

			for (int i = 0; i < 4; ++i) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx < 1 || nx > r || ny < 1 || ny > c) continue; // 범위 밖
				if (forest[nx][ny] == 'X' || water_visit[nx][ny]) continue; // 못 감
				if (cnt[nx][ny] == -1) {
					cnt[nx][ny] = cnt[cx][cy] + 1;
					que.push({ nx, ny });
				}
			}
		}
	}
}

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int r, c;
	string str;
	cin >> r >> c;
	pair<int, int> start, des;
	for (int i = 1; i <= r; ++i) {
		cin >> str;
		for (int j = 1; j <= c; ++j) {
			forest[i][j] = str[j - 1];
			if (str[j - 1] == 'S') start.first = i, start.second = j;
			if (str[j - 1] == 'D') des.first = i, des.second = j;
		}
	}

	BFS(r, c, start, des);

	if (cnt[des.first][des.second] == -1) cout << "KAKTUS";
	else cout << cnt[des.first][des.second];

	return 0;
}