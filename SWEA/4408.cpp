// SWEA4408 자기 방으로 돌아가기
#include<iostream>
#include<map>
#include<string.h>
#include<set>
#include<algorithm>
using namespace std;
const long long MOD = (1 << 30) - 1;

bool visited[401];
pair<int, int> p[401];

bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
	return p1.first < p2.first;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, a, b;
		cin >> n;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; ++i) {
			cin >> a >> b;
			p[i] = { min(a, b), max(a, b) };
		}

		sort(p, p + n, [](const pair<int, int>& p1, const pair<int, int>& p2) {
			if (p1.first == p2.first) return p1.second < p2.second;
			return p1.first < p2.first;
		});
		int group = 0;
		for (int i = 0; i < n; ++i) {
			if (!visited[i]) {
				int base = p[i].second % 2 ? p[i].second + 1 : p[i].second;
				visited[i] = true;

				for (int j = i + 1; j < n; ++j) {
					if (!visited[j] && p[j].first > base) {
						visited[j] = true;
						base = p[j].second % 2 ? p[j].second + 1 : p[j].second;
					}
				}

				group++;
			}
		}

		printf("#%d %d\n", test_case, group);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}