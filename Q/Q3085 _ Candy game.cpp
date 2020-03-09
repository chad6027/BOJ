// Q3085 ���� ����

// 1���� ���ѽð� ������ DP�ΰ� ��� ���.
// DP�δ� �ڽ� ��� ���Ʈ������ ��Ʈ ����.

// SearchTable �Լ��� �� ��Ȳ���� ���� �� �ִ� ������ �ִ� ������ ����.
// main �κп� ù��° ���� for���� ���η� �ű�� ��� (ex. 1<->2 , 2<->3 ...)
// �ι�° ���� for���� ���η� �ű�� ���
// �ð��� ���̱� ����, �ű� �� ���� �ΰ��� ������ ������ continue �ϴ� ������ �����ߴ�.
// �� ������ �ذ��� ��� algorithm ���̺귯���� max, min�� �� �� ���� �� ū ���� �����ϱ� ���� if������ ó���ߴ�..

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