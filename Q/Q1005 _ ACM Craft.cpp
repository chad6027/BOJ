// Q1005 ACM craft

// 위상 정렬을 이용해 풀이하였다. DP만으로 도전하다가 막히는 부분이 있어 위상 정렬로 방향을 틀었다. ( 위상 정렬 방법을 까먹어 검색해본건 함정이다.)
// 위상 정렬을 통해 DP로 풀이한다.
// x번 건물이 y번 건물의 선행조건이면, 
// (x번 건물을 짓는 데까지 걸린 시간(time[x]) + x번 건물을 짓는 데 걸리는 시간(minTime[x])) 과 (y번 건물을 지을 수 있게 된 시간 중 최솟값(minTime[y])) 중 작은 값을 minTime[y]에 저장
// 위 방식으로 정렬 후, 내가 짓고자 한 건물의 번호를 w라 하면, w를 짓는 데 걸리는 시간(time[w]) + w를 지을 수 있게 된 시간 중 최솟값(minTime[w]) 이 정답이 된다.

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