// SWEA3000 중간값 구하기
// Priority Queue 응용
#include<iostream>
#include<queue>
#include<algorithm>
const int MAX_N = 1e5 + 1;
const int MOD = 20171109;
using namespace std;

int n;
priority_queue<int> minPQ, maxPQ;

int solve() {
    int sum = 0;

    int x, y;
    while (n--) {
        cin >> x >> y;
        int low = min(x, y), high = max(x, y);

        maxPQ.push(low);
        minPQ.push(-high);

        while (-minPQ.top() < maxPQ.top()) {
            low = -minPQ.top();
            high = maxPQ.top();

            maxPQ.pop();
            minPQ.pop();

            maxPQ.push(low);
            minPQ.push(-high);
        }

        sum = (sum + maxPQ.top()) % MOD;

    }

    while (!maxPQ.empty()) { maxPQ.pop(); }
    while (!minPQ.empty()) { minPQ.pop(); }

    return sum;
}

int main(int argc, char** argv)
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    int T;

    //freopen("input.txt", "r", stdin);
    cin >> T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int first;
        cin >> n >> first;
        maxPQ.push(first);

        printf("#%d %d\n", test_case, solve());
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}