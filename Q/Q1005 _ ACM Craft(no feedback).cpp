#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

int time[1001];
int degree[1001];
int minTime[1001];
vector<int> v[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T, N, K, W;
	int cur, next;
	int ans;
	queue<int> q;
	cin >> T;

	while (T--) {
		ans = 0;
		memset(degree, 0, sizeof(degree));
		memset(minTime, 0, sizeof(minTime));
		cin >> N >> K;
		for (int i = 1; i <= N; i++)
			cin >> time[i];

		for (int i = 1; i <= K; i++) {
			cin >> cur >> next;
			v[cur].push_back(next);
			degree[next]++;
		}

		cin >> W;

		//위상정렬
		
		for (int i = 1; i <= N; i++) {
			if (!degree[i]) {
				q.push(i);
			}
		}
		
		while (degree[W] > 0) {
			cur = q.front();
			q.pop();
			for (int i = 0; i < v[cur].size(); i++) {
				minTime[v[cur][i]] = max(minTime[v[cur][i]], minTime[cur] + time[cur]);
				if (--degree[v[cur][i]] == 0)
					q.push(v[cur][i]);
			}
			
		}
		ans = time[W] + minTime[W];
		cout << ans << '\n';

		while (!q.empty())
			q.pop();

		for (int i = 1; i <= 1000; i++) {
			if(!v[i].empty())
				v[i].clear();
		}

	}


	return 0;
}