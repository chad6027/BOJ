// Q1248 _ 맞춰봐

// 쉽지만 생각보다 까다로운 브루트포스 문제다. 
// 영어 지문으로 보면 더 이해하기 쉬운 이상한(?) 문제였다.
// 입력받은 string을 n x n짜리 배열로 풀어서 만들어보면 n개의 숫자들의 부호나 0인지 알 수 있다.
// 이걸 이용해서 브루트포스로 해결해보자 

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 2147483647;
const int MAX_N = 1e5 + 1;
const int MOD = 1e+9;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int n;
char sign[11][11];
int num[11][11] = { 0, };

void DFS(int cur) {

	if (cur == n) {
		for (int i = 0; i < n; ++i) cout << num[i][i] << ' ';
		exit(0);
	}
	if (sign[cur][cur] == '0') {
		num[cur][cur] = 0;
		for (int j = cur - 1; j >= 0; --j) {
			num[j][cur] = num[j][cur - 1] + num[cur][cur];
		}
		DFS(cur + 1);
	}
	else {
		for (int i = 1; i <= 10; ++i) {
			if (sign[cur][cur] == '+') num[cur][cur] = i;
			else if (sign[cur][cur] == '-') num[cur][cur] = -i;

			bool isRight = true;
			for (int j = cur - 1; j >= 0; --j) {
				num[j][cur] = num[j][cur - 1] + num[cur][cur];
				if ((num[j][cur] == 0 && sign[j][cur] != '0')
					|| (num[j][cur] < 0 && sign[j][cur] != '-')
					|| (num[j][cur] > 0 && sign[j][cur] != '+')
					) {
					isRight = false;
					break;
				}
			}

			if (isRight) DFS(cur + 1);

		}
	}
}


int main()
{
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> n >> str;
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			sign[i][j] = str[cur + (j - i)];
		}
		cur += (n - i);
	}

	DFS(0);

	return 0;
}