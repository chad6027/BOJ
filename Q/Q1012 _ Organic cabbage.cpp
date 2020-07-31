#include <iostream>
#include <queue>
#include <string.h>
#include <utility>
using namespace std;

bool cabbage[50][50];
bool visit[50][50];
int N, M;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void BFS(int x, int y) {
	queue<pair<int, int>> que;
	que.push({ x, y });
	int cur_x, cur_y, next_x, next_y;

	while (!que.empty()){
		cur_x = que.front().first;
		cur_y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
				next_x = cur_x + dx[i];
				next_y = cur_y + dy[i];
				if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M) {
					if (!visit[next_x][next_y] && cabbage[next_x][next_y]) {
						visit[next_x][next_y] = true;
						que.push({ next_x, next_y });
					}
				}
			
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T, K, X, Y, ans;
	
	cin >> T;
	while (T--) {
		ans = 0;
		memset(cabbage, 0, sizeof(cabbage));
		memset(visit, 0, sizeof(visit));
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			cabbage[Y][X] = true;
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!cabbage[i][j])
					continue;
				else {
					if (visit[i][j]) {
						continue;
					}
					else {
						ans++;
						BFS(i, j);

					}
				}
			}
		}



		cout << ans << '\n';

	}

	return 0;
}