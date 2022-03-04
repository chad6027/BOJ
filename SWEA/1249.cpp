// SWEA1249 보급로
// BFS

#include<iostream>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
const int INF = 987654321;
const int MOD = 1000000007;
const int MAX_N = 1e5 + 2;

int depth[101][101];
int dp[101][101];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int n;
bool visited[101][101];

void BFS() {
    queue<pair<int, int>> que;
    que.push({ 0, 0 });

    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) dp[i][j] = INF;
    dp[0][0] = 0;
    visited[0][0] = true;

    while (!que.empty()) {
        int cx = que.front().first;
        int cy = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            if (!visited[nx][ny] || dp[nx][ny] > dp[cx][cy] + depth[nx][ny]) {
                visited[nx][ny] = true;
                dp[nx][ny] = dp[cx][cy] + depth[nx][ny];
                que.push({ nx, ny });
            }
        }
    }

}


int main(int argc, char** argv)
{
    ios::ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        memset(dp, 0, sizeof(dp));
        memset(visited, 0, sizeof(visited));
        cin >> n;
        for (int i = 0; i < n; ++i) {
            string str;
            cin >> str;
            for (int j = 0; j < n; ++j) depth[i][j] = str[j] - '0';
        }

        BFS();
        printf("#%d %d\n", test_case, dp[n - 1][n - 1]);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}