// Q1002 Turret

// �� ���� ������ ������ �˾ƾ� �ذ��� �� �ִ� ��������.
// �� ������� �ߴٰ� �ι����� Ʋ���� ���ۿ� �� ���� ������ ���� �˻��ϰ� correct �޾Ƴ�.
// ���п� ���� �ڵ��� �˻��ؼ� Ǯ���ٴ� ���� �ʹ� ¥�������� ���� �������̾��� ������ �����ϰ� �Ѱ��.

#include <iostream>
#include <algorithm>
#include <utility>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	int first_x, first_y, first_r, second_x, second_y, second_r;
	int d, r;
	
	while (T--) {
		cin >> first_x >> first_y >> first_r >> second_x >> second_y >> second_r;
		
		// first�� �� ū ���� �ǰ� swap
		if (first_r < second_r) {
			swap(first_x, second_x);
			swap(first_y, second_y);
			swap(first_r, second_r);
		}
		// d = �� ���� �߽� ������ �Ÿ��� ����
		d = (first_x - second_x) * (first_x - second_x) + (first_y - second_y) * (first_y - second_y);
		// r = �� ���� �������� ��
		r = first_r + second_r;

		// �߽��� ���� ��
		if (d == 0) {
			if (first_r == second_r) {
				cout << -1 << '\n';
			}
			else
				cout << 0 << '\n';
		}
		// �߽��� ���� ���� ��
		else {
			// �߽� ������ �Ÿ��� �������� �պ��� ũ�ų� �������� ������ ���� ��, �� ���� ������ �ʴ´�.
			if ((first_r + second_r) * (first_r + second_r) < d || d < (first_r - second_r) * (first_r - second_r) ) {
				cout << 0 << '\n';
			}
			// �߽� ������ �Ÿ��� �������� �հ� ���ų� �������� ���� ���� ��, �� ���� �� ������ ������.
			else if ((first_r + second_r) * (first_r + second_r) == d || (first_r - second_r) * (first_r - second_r) == d) {
				cout << 1 << '\n';
			}
			// �߽� ������ �Ÿ��� �������� �պ��� �۰ų� �������� ������ Ŭ ��, �� ���� �� ������ ������.
			else if ((first_r - second_r) * (first_r - second_r) < d && d < (first_r + second_r) * (first_r + second_r) ){
				cout << 2 << '\n';
			}
		}
	}




	return 0;
}