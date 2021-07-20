// 플로이드-와샬을 이용하여 O(n^3)에 모든 정점에 대해 정점 -> 모든 정점으로 가는 최소 비용을 구한다
// 이후 한 정점(x)를 잡아서 start -> x 비용 + x -> a 비용 + x -> b 비용의 최소값을 구해주면 된다.

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 987654321;

int dp[201][201] = { 0, };
int num_v;
void floyd_warshall() {
    for (int i = 1; i <= num_v; ++i) {
        for (int j = 1; j <= num_v; ++j) {
            if (i == j) continue;
            if (dp[i][j] == 0) dp[i][j] = 987654321;
        }
    }

    for (int via = 1; via <= num_v; ++via)
        for (int from = 1; from <= num_v; ++from)
            for (int to = 1; to <= num_v; ++to)
                if (dp[from][to] > dp[from][via] + dp[via][to])
                    dp[from][to] = dp[from][via] + dp[via][to];
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    num_v = n;
    for (int i = 0; i < fares.size(); ++i) {
        int from = fares[i][0];
        int to = fares[i][1];
        int c = fares[i][2];
        dp[from][to] = c;
        dp[to][from] = c;
    }

    floyd_warshall();
    answer = INF;
    for (int via = 1; via <= n; ++via) {
        if (dp[s][via] == INF || dp[via][a] == INF || dp[via][b] == INF) continue;
        answer = min(answer, dp[s][via] + dp[via][a] + dp[via][b]);

    }


    return answer;
}