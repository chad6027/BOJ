// SWEA 1767 프로세서 연결하기
// 백트래킹

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

int board[13][13];
bool visited[13][13];
int dir[4][2] = { {0, -1}, {0 , 1}, {-1, 0}, {1, 0} };
pair<int, int> core[13];
pair<int, int> dist[13][4];
int ans[13];
int numCore = 0;
int n;
int getLineLength(int x, int y, int& dirNum) {
    int count = 0;
    x += dir[dirNum][0];
    y += dir[dirNum][1];
    while (0 <= x && x < n && 0 <= y && y < n) {
        if (board[x][y]) return INF;

        x += dir[dirNum][0];
        y += dir[dirNum][1];
        count++;
    }

    return count;
}

void findShortedDist(int cur) {
    int x = core[cur].first;
    int y = core[cur].second;

    if (x == 0 || y == 0) return;

    for (int i = 0; i < 4; ++i) {
        dist[cur][i] = { getLineLength(x, y, i), i };
    }

    sort(dist[cur], dist[cur] + 4, less<pair<int, int>>());

    //cout << "x : " << x << "\ty : " << y << endl;
    //for (int i = 0; i < 4; ++i) cout << dist[cur][i].first << endl;
}

bool canGo(int cur, int dirNum) {
    int x = core[cur].first;
    int y = core[cur].second;
    x += dir[dirNum][0];
    y += dir[dirNum][1];
    while (0 <= x && x < n && 0 <= y && y < n) {
        if (visited[x][y] || board[x][y]) return false;
        x += dir[dirNum][0];
        y += dir[dirNum][1];
    }

    return true;
}

void checkVisited(int cur, int dirNum, bool v) {
    int x = core[cur].first;
    int y = core[cur].second;
    x += dir[dirNum][0];
    y += dir[dirNum][1];
    while (0 <= x && x < n && 0 <= y && y < n) {
        visited[x][y] = v;
        x += dir[dirNum][0];
        y += dir[dirNum][1];
    }
}
void recur(int cur, int len, int cnt) {

    if (cur == numCore) {
        ans[cnt] = min(ans[cnt], len);
        return;
    }

    if (core[cur].first == 0 || core[cur].second == 0) {
        recur(cur + 1, len, cnt + 1);
    }
    bool isSelected = false;
    for (int i = 0; i < 4; ++i) {
        if (dist[cur][i].first == INF) continue;

        if (canGo(cur, dist[cur][i].second)) {

            len += dist[cur][i].first;
            checkVisited(cur, dist[cur][i].second, true);

            recur(cur + 1, len, cnt + 1);

            len -= dist[cur][i].first;
            checkVisited(cur, dist[cur][i].second, false);

            isSelected = true;
        }
    }

    if (isSelected) return;
    else recur(cur + 1, len, cnt);
}

int main(int argc, char** argv)
{
    ios::ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        memset(visited, 0, sizeof(visited));
        cin >> n;
        numCore = 0;
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
            if (board[i][j]) core[numCore++] = { i, j };
        }

        for (int i = 0; i < numCore; ++i) findShortedDist(i);
        for (int i = 0; i <= numCore; ++i) ans[i] = INF;
        recur(0, 0, 0);
        int ANSWER = INF;
        for (int i = numCore; i >= 0 && ANSWER == INF; --i) {
            ANSWER = min(ANSWER, ans[i]);
        }

        printf("#%d %d\n", test_case, ANSWER);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}