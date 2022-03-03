// SWEA 1251 하나로
// MST
#include<iostream>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
const int MOD = 1000000007;
const int MAX_N = 1e4 + 1;

pair<double, pair<int, int>> edges[5000001];
pair<int, int> loc[1001];
int anc[1001];
bool compare(const pair<double, pair<int, int>>& p1, const pair<double, pair<int, int>>& p2) {
    if (p1.first == p2.first) return p1.second.first < p2.second.first;
    return p1.first < p2.first;
}
int union_find(int cur) {
    if (anc[cur] == cur) return cur;
    else return anc[cur] = union_find(anc[cur]);
}

double MST(int& n) {
    int m = (n * (n - 1)) / 2;

    for (int i = 0; i < n; ++i) anc[i] = i;

    sort(edges, edges + m, compare);

    double sum = 0;
    int connect = 0;
    for (int i = 0; i < m && connect != n - 1; ++i) {
        double cost = edges[i].first;

        int root_a = union_find(edges[i].second.first);
        int root_b = union_find(edges[i].second.second);

        if (root_a == root_b) continue;
        sum += cost;
        anc[root_a] = anc[root_b] = min(root_a, root_b);
        connect++;
    }
    return sum;
}

int main(int argc, char** argv)
{
    ios::ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) cin >> loc[i].first;
        for (int i = 0; i < n; ++i) cin >> loc[i].second;

        int cur = 0;
        for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
            double cost = pow(loc[i].first - loc[j].first, 2) + pow(loc[i].second - loc[j].second, 2);
            edges[cur++] = { cost, {i , j} };
        }

        double e;
        cin >> e;

        long long ans = round(MST(n) * e);

        printf("#%d %ld\n", test_case, ans);

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}