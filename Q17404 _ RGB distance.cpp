#include <iostream>
#include <algorithm>
using namespace std;
int RGB[3000];
int d[3][3000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, Min;
	cin >> N;
	Min = 1000 * N;
	for (int i = 0; i < 3 * N; i++) {
		cin >> RGB[i];
	}

	for (int j = 0; j < 3; j++) {
		d[0][0] = RGB[j];
		d[1][0] = RGB[j];
		d[2][0] = RGB[j];
		for (int i = 1; i < N; i++) {
			d[0][i] = min(d[1][i - 1], d[2][i - 1]) + RGB[3 * i];
			d[1][i] = min(d[0][i - 1], d[2][i - 1]) + RGB[3 * i + 1];
			d[2][i] = min(d[0][i - 1], d[1][i - 1]) + RGB[3 * i + 2];
			d[j][1] = 1001 * 2;
		}

		if (j == 0) {
			Min = min(Min, min(d[1][N - 1], d[2][N - 1]));
		}
		else if (j == 1) {
			Min = min(Min, min(d[0][N - 1], d[2][N - 1]));
		}
		else {
			Min = min(Min, min(d[0][N - 1], d[1][N - 1]));
		}
	}



	cout << Min;
	return 0;
}
