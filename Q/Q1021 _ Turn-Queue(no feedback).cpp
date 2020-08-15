#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>
#include <math.h>
using namespace std;
bool visit[51];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M;
	memset(visit, 0, sizeof(visit));
	cin >> N >> M;
	int ans = 0, cur = 0, size = N, go;
	queue<int> q;
	for (int i = 1; i <= M; i++) {
		cin >> go;
		q.push(go - 1);
	}

	while (!q.empty()) {
		int front = q.front();
		q.pop();

		go = 0;
		while (cur != front) {
			cur = (cur + 1) % N;
			if (!visit[cur])
				go++;
		}

		go = min(go, size - go);
		visit[front] = true;

		while (visit[cur] && size != 1) {
			cur = (cur + 1) % N;
		}
	
		ans += go;
		size--;
	}

	cout << ans << '\n';

	return 0;
}