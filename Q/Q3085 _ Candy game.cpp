// Q3085 사탕 게임

// 1초의 제한시간 때문에 DP인가 잠깐 고민.
// DP로는 자신 없어서 브루트포스로 루트 변경.

// SearchTable 함수는 그 상황에서 먹을 수 있는 사탕의 최대 개수를 리턴.
// main 부분에 첫번째 이중 for문은 가로로 옮기는 경우 (ex. 1<->2 , 2<->3 ...)
// 두번째 이중 for문은 세로로 옮기는 경우
// 시간을 줄이기 위해, 옮길 때 만약 두개의 색깔이 같으면 continue 하는 식으로 진행했다.
// 이 문제를 해결할 당시 algorithm 라이브러리에 max, min을 쓸 줄 몰라서 더 큰 값을 저장하기 위해 if문으로 처리했다..

#include <iostream>
using namespace std;
char a[50][50];
int SearchTable(int& n) {
	int tmp = 0, max_c = 0;
	for (int i = 0; i < n; i++) {
		tmp = 0;
		for (int j = 1; j < n; j++) {
			if (a[i][j] == a[i][j - 1])
				tmp++;
			else {
				if (tmp > max_c) {
					max_c = tmp;
				}
				tmp = 0;
			}
		}
		if (tmp > max_c) {
			max_c = tmp;
		}

	}

	for (int i = 0; i < n; i++) {
		tmp = 0;
		for (int j = 1; j < n; j++) {
			if (a[j][i] == a[j - 1][i])
				tmp++;
			else {
				if (tmp > max_c) {
					max_c = tmp;
				}
				tmp = 0;
			}
		}
		if (tmp > max_c) {
			max_c = tmp;
		}
	}
	
	return max_c;
}

int main() {
	int n, max_c = 0, tmp = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	tmp = SearchTable(n);
	if (tmp > max_c)
		max_c = tmp;

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {

			if (a[i][j] == a[i][j - 1])
				continue;
			else {
				swap(a[i][j], a[i][j - 1]);
				tmp = SearchTable(n);
				if (tmp > max_c)
					max_c = tmp;
				swap(a[i][j], a[i][j - 1]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (a[j][i] == a[j - 1][i])
				continue;
			else {
				swap(a[j][i], a[j - 1][i]);
				tmp = SearchTable(n);
				if (tmp > max_c)
					max_c = tmp;
				swap(a[j][i], a[j - 1][i]);
			}
		}
	}

	cout << max_c+1;
	return 0;
}