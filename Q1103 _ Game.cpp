// Q1103 _ 게임

// DFS 완전탐색 문제
// TLE와 MLE를 피하기 위해 dp를 같이 사용한다.



#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = 2147483647;
const int MAX = 10e+8;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
int board[51][51] = { 0, };
int dp[51][51] = { 0, };
bool visited[51][51] = { 0, };
int dx[4] = { 0 , 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int DFS(int cur_x, int cur_y) {

	visited[cur_x][cur_y] = true;
	dp[cur_x][cur_y] = 0;
	for (int i = 0; i < 4; ++i) {
		int nx = cur_x + dx[i] * board[cur_x][cur_y];
		int ny = cur_y + dy[i] * board[cur_x][cur_y];

		if (nx < 1 || ny < 1 || nx > n || ny > m) continue;

		if (!visited[nx][ny] && board[nx][ny] != 0) {
			if (dp[nx][ny] == -1) dp[cur_x][cur_y] = max(dp[cur_x][cur_y], DFS(nx, ny) + 1);
			else dp[cur_x][cur_y] = max(dp[cur_x][cur_y], dp[nx][ny] + 1);
		}
		else {
			if (visited[nx][ny]) { // 갔던 곳을 또 가면 무한루프
				cout << -1 << '\n';
				exit(0);
			}
		}
	}
	visited[cur_x][cur_y] = false;
	return dp[cur_x][cur_y];
}

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	string str;
	for (int i = 1; i <= n; ++i) {
		cin >> str;
		for (int j = 1; j <= m; ++j) {
			if (str[j - 1] == 'H')  board[i][j] = 0;
			else board[i][j] = str[j - 1] - '0';
		}
	}
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) dp[i][j] = -1;
	int ans = DFS(1, 1);
	cout << ans + 1;


	return 0;
}