#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = 2147483647;
const int MAX_N = 10e+4 + 1;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int board[10][10] = { 0, };
bool numInUD[10][10] = { 0 , };
bool numInLR[10][10] = { 0 , };
bool numInThree[3][3][10] = { 0, };
vector<pair<int, int>> zeros;

void DFS(int cur) {
	if (cur == zeros.size()) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cout << board[i][j] << ' ';
			}
			cout << endl;
		}
		exit(0);
	}


	int cx = zeros[cur].first;
	int cy = zeros[cur].second;
	for (int i = 1; i < 10; ++i) {
		if (!numInUD[cy][i] && !numInLR[cx][i]
			&& !numInThree[cx / 3][cy / 3][i]) {
			numInUD[cy][i] = true;
			numInLR[cx][i] = true;
			numInThree[cx / 3][cy / 3][i] = true;
			board[cx][cy] = i;
			DFS(cur + 1);
			numInUD[cy][i] = false;
			numInLR[cx][i] = false;
			numInThree[cx / 3][cy / 3][i] = false;
			board[cx][cy] = 0;

		}
	}
}


int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for (int i = 0; i < 9; ++i) for (int j = 0; j < 9; ++j) {
		cin >> board[i][j];
		if (board[i][j] == 0) zeros.push_back({ i, j });
		else {
			numInUD[j][board[i][j]] = true;
			numInLR[i][board[i][j]] = true;
			numInThree[i / 3][j / 3][board[i][j]] = true;
		}
	}
	DFS(0);


	return 0;
}