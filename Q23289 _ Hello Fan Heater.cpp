// Q23289 ��ǳ�� �ȳ�!
// ���������̴�.
// ���⿡ ���� �����ϰ� BFS�� �ڵ����ָ� �Ǵµ�.. ���� ���� �׷��� ���������� �ʴ� ����
// 1 ��
// 2 ��
// 3 ��
// 4 ��
// BFS�� ������ �� canGo�Լ��� ���� ���� ���޵Ǵ����� Ȯ���ϰ�
// controlTemp �Լ��� ���� �����Ѵ�
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = 2147483647;
const int MAX = 2 * 1e5 + 1;
const int MOD = 1e9 + 3;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int dir[] = { 0, 1, 2, 3, 4, 5 };

int dx[5][3] = {
	{0, 0, 0},
	{-1, 0, 1},
	{-1, 0, 1},
	{-1, -1, -1},
	{1, 1, 1},
};
int dy[5][3] = {
	{0, 0, 0},
	{1, 1, 1},
	{-1, -1, -1},
	{-1, 0, 1},
	{-1, 0, 1},
};

int r, c, k, w;

int dif[21][21] = { 0, };
int heat_on[21][21] = { 0, };
int hot[21][21] = { 0, };
int room[21][21] = { 0, };
bool block[21][21][2] = { 0, };
bool visited[21][21] = { 0, };


bool canGo(int& cx, int& cy, int& nx, int& ny, int& dir, int& dir_second) {

	switch (dir) {
	case 1:
		switch (dir_second) {
		case 0:
			if (block[cx][cy][0] || block[cx - 1][cy][1]) return false;
			else return true;
		case 1:
			if (block[cx][cy][1]) return false;
			else return true;
		case 2:
			if (block[cx + 1][cy][0] || block[cx + 1][cy][1]) return false;
			else return true;
		}

	case 2:
		switch (dir_second) {
		case 0:
			if (block[cx][cy][0] || block[cx - 1][cy - 1][1]) return false;
			else return true;
		case 1:
			if (block[cx][cy - 1][1]) return false;
			else return true;
		case 2:
			if (block[cx + 1][cy][0] || block[cx + 1][cy - 1][1]) return false;
			else return true;
		}
	case 3:
		switch (dir_second) {
		case 0:
			if (block[cx][cy - 1][0] || block[cx][cy - 1][1]) return false;
			else return true;
		case 1:
			if (block[cx][cy][0]) return false;
			else return true;
		case 2:
			if (block[cx][cy + 1][0] || block[cx][cy][1]) return false;
			else return true;
		}
	case 4:
		switch (dir_second) {
		case 0:
			if (block[cx + 1][cy - 1][0] || block[cx][cy - 1][1]) return false;
			else return true;
		case 1:
			if (block[cx + 1][cy][0]) return false;
			else return true;
		case 2:
			if (block[cx + 1][cy + 1][0] || block[cx][cy][1]) return false;
			else return true;
		}
	}
}

void fillOn(int x, int y, int dir) {

	memset(visited, 0, sizeof(visited));

	queue<pair<int, int>> que;
	switch (dir) {
	case 1:
		que.push({ x, y + 1 });
		break;
	case 2:
		que.push({ x, y - 1 });
		break;
	case 3:
		que.push({ x - 1, y });
		break;
	case 4:
		que.push({ x + 1, y });
		break;
	}
	int temp = 6;
	while (!que.empty()) {
		int q_size = que.size();

		if (--temp == 0) return;

		while (q_size--) {
			int cx = que.front().first;
			int cy = que.front().second;
			que.pop();
			if (visited[cx][cy]) continue;

			visited[cx][cy] = true;
			heat_on[cx][cy] += temp;

			for (int i = 0; i < 3; ++i) {
				int nx = cx + dx[dir][i];
				int ny = cy + dy[dir][i];

				if (nx < 1 || ny < 1 || nx > r || ny > c) continue;

				if (!visited[nx][ny] && canGo(cx, cy, nx, ny, dir, i)) {
					que.push({ nx, ny });
				}
			}
		}
	}
}

void controlTemp() {

	for (int cx = 1; cx <= r; ++cx) for (int cy = 1; cy <= c; ++cy) {
		// �Ʒ�
		int nx = cx + 1;
		int ny = cy;
		if (nx <= r && !block[nx][ny][0]) {
			int temp = floor((abs(hot[nx][ny] - hot[cx][cy])) / 4);
			if (hot[cx][cy] < hot[nx][ny]) {
				dif[cx][cy] += temp;
				dif[nx][ny] -= temp;
			}
			else {
				dif[cx][cy] -= temp;
				dif[nx][ny] += temp;
			}
		}

		// ������
		nx = cx;
		ny = cy + 1;
		if (ny <= c && !block[cx][cy][1]) {
			int temp = floor((abs(hot[nx][ny] - hot[cx][cy])) / 4);
			if (hot[cx][cy] < hot[nx][ny]) {
				dif[cx][cy] += temp;
				dif[nx][ny] -= temp;
			}
			else {
				dif[cx][cy] -= temp;
				dif[nx][ny] += temp;
			}
		}
	}

	for (int i = 1; i <= r; ++i) for (int j = 1; j <= c; ++j) {
		hot[i][j] += dif[i][j];
		dif[i][j] = 0;
	}

	for (int i = 1; i <= r; ++i) {
		if (hot[i][1]) hot[i][1]--;
		if (hot[i][c]) hot[i][c]--;
	}
	for (int j = 2; j < c; ++j) {
		if (hot[1][j]) hot[1][j]--;
		if (hot[r][j]) hot[r][j]--;
	}

}

bool checkOverK() {
	for (int i = 1; i <= r; ++i) for (int j = 1; j <= c; ++j) if (room[i][j] == 5 && hot[i][j] < k) return false;

	return true;
}

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> r >> c >> k;
	for (int i = 1; i <= r; ++i)for (int j = 1; j <= c; ++j) cin >> room[i][j];

	cin >> w;
	for (int i = 0; i < w; ++i) {
		int x, y, t;
		cin >> x >> y >> t;
		block[x][y][t] = true;
	}

	// init
	for (int i = 1; i <= r; ++i)for (int j = 1; j <= c; ++j) {
		if (0 < room[i][j] && room[i][j] < 5) {
			fillOn(i, j, room[i][j]);
		}
	}

	int choco = 0;
	while (true) {
		// 1. �ٶ�
		for (int i = 1; i <= r; ++i) for (int j = 1; j <= c; ++j) hot[i][j] += heat_on[i][j];

		// 2, 3. �µ� ����
		controlTemp();

		// 4. ���ݸ�
		choco++;

		// 5.
		if (checkOverK() || choco == 101) break;
	}

	cout << choco;

	return 0;
}