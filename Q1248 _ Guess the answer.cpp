// Q1248 _ �����

// ������ �������� ��ٷο� ���Ʈ���� ������. 
// ���� �������� ���� �� �����ϱ� ���� �̻���(?) ��������.
// �Է¹��� string�� n x n¥�� �迭�� Ǯ� ������ n���� ���ڵ��� ��ȣ�� 0���� �� �� �ִ�.
// �̰� �̿��ؼ� ���Ʈ������ �ذ��غ��� 

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