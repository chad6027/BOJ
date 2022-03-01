// SWEA1868 파핑파핑 지뢰찾기
// DFS
#include<iostream>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
const int MOD = 1000000007;
const int MAX_N = 1e5 + 2;

int n;
char board[301][301];
int bomb[301][301];
bool isClicked[301][301];
int dx[] = { 0 ,0 ,1, -1, -1, -1, 1, 1 };
int dy[] = { 1 ,-1 ,0, 0, 1, -1, -1, 1 };
int getNumOfBomb(int& x, int& y) {
    int count = 0;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

        if (board[nx][ny] == '*') count++;
    }
    return count;
}

void DFS(int cx, int cy) {

    isClicked[cx][cy] = true;

    if (bomb[cx][cy] != 0) return;

    for (int i = 0; i < 8; ++i) {
        int nx = cx + dx[i];
        int ny = cy + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

        if (!isClicked[nx][ny] && board[nx][ny] != '*') DFS(nx, ny);
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
        memset(bomb, 0, sizeof(bomb));
        memset(isClicked, 0, sizeof(isClicked));

        cin >> n;
        string str;
        for (int i = 0; i < n; ++i) {
            cin >> str;
            for (int j = 0; j < n; ++j) board[i][j] = str[j];
        }
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
            if (board[i][j] == '*') bomb[i][j] = -1;
            else bomb[i][j] = getNumOfBomb(i, j);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
            if (!isClicked[i][j] && bomb[i][j] == 0) {
                DFS(i, j);
                ans++;
            }
        }

        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
            if (!isClicked[i][j] && board[i][j] != '*') {
                ans++;
            }
        }

        printf("#%d %d\n", test_case, ans);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}