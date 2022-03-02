// SWEA1855 영준이의 진짜 BFS
// LCA

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

int depth[MAX_N];
int anc[MAX_N][20];
int max_level;
vector<int> graph[MAX_N];

void initTree() {

    queue<pair<int, int>> que;
    que.push({ 1,0 });
    while (!que.empty()) {
        int cur = que.front().first;
        int parent = que.front().second;
        que.pop();

        depth[cur] = depth[parent] + 1;

        anc[cur][0] = parent;

        for (int i = 1; i <= max_level; ++i) {
            anc[cur][i] = anc[anc[cur][i - 1]][i - 1];
        }

        for (int next : graph[cur]) {
            que.push({ next, cur });
        }
    }

}

int find_LCA(int a, int b) {
    if (depth[a] != depth[b]) {
        if (depth[a] > depth[b]) swap(a, b);

        for (int i = max_level; i >= 0; --i) {
            if (depth[a] <= depth[anc[b][i]]) b = anc[b][i];
        }
    }

    int LCA = a;

    if (a != b) {
        for (int i = max_level; i >= 0; --i) {
            if (anc[a][i] != anc[b][i]) {
                a = anc[a][i];
                b = anc[b][i];
            }
            LCA = anc[a][i];
        }
    }

    return LCA;
}

long long BFS() {

    queue<int> que;
    que.push(1);
    long long dist = 0;

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (int next : graph[cur]) que.push(next);

        if (que.empty()) return dist;

        int lca = find_LCA(cur, que.front());
        dist += (long long)abs(depth[cur] - depth[lca]) + (long long)abs(depth[lca] - depth[que.front()]);
    }

    return dist;
}


int main(int argc, char** argv)
{
    ios::ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int test_case;
    int T;
    cin >> T;
    max_level = (int)floor(log2(MAX_N));
    depth[0] = -1;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        memset(anc, 0, sizeof(anc));

        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) graph[i].clear();

        for (int i = 2; i <= n; ++i) {
            int parent;
            cin >> parent;
            graph[parent].push_back(i);
        }
        depth[0] = -1;
        initTree();
        long long ans = BFS();
        printf("#%d %lld\n", test_case, ans);

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}