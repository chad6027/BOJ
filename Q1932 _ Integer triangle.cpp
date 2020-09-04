// 1932 _ 정수 삼각형

// 삼각형에 각 칸에 번호와 몇번째 줄인지를 생각
//			   row
//    1			1
//   2 3		2
//  4 5 6		3
// 7 8 9 10		4

// 저것을 토대로 보면 n번째 줄 첫번째 숫자는 n-1번째 줄 첫번째 숫자만이 선택가능 (ex. 7번은 4번만이 선택가능)
// 그 이후는 row만큼 뺀 인덱스와 와 거기에 +1한 인덱스에 가서 더 큰 값을 선택하고 해야됨 (ex. 8번은 4번과 5번 둘 다 선택할 수 있기 때문에 더 큰 값 선택 후 자신을 더함)
// 마지막은 n-1번째 줄 마지막 인덱스만이 선택 가능 (ex. 10번은 6번만이 선택가능)

// 이 아이디어를 토대로 생각해보면 n번째 첫번째 인덱스를 f, 마지막 인덱스를 l, 중간을 m이라 하면
// n-1번째 줄 첫번째 인덱스는 f - n + 1, 마지막 인덱스는 l - n이고
// 중간은 m - n 과 m - n + 1 이다.

// 따라서 이중 for문으로 몇번째 줄인지와, (그 줄의 첫번째 값인지, 마지막 값인지, 둘다 아닌지) 를 판단해서 점화식을 세운다.

#include <iostream>
#include <algorithm>
using namespace std;
int a[250 * 501 + 1]; //삼각형의 크기가 500까지이므로 (500 * 501 / 2) 와 1번 인덱스부터 시작하기 위해 + 1
int d[250 * 501 + 1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, ans = 0, f = 1;
	cin >> n;
	for (int i = 1; i <= (n*n + n) / 2; i++) {
		cin >> a[i];
	}

	//dp
	for(int row = 1; row <= n; row++){
		
		for (int i = f; i <= (row*row + row) / 2; i++) {
			if (i == f) {
				d[i] = d[i - row + 1] + a[i];
			}
			else if (i == (row*row + row) / 2) {
				d[i] = d[i - row] + a[i];
			}
			else {
				d[i] = max(d[i - row + 1], d[i - row]) + a[i];
			}

			ans = max(ans, d[i]);

		}
		f += row;
	
	}

	//잘계산했는지 확인해보기 위해 썼던 코드
	//for (int i = 1; i <= n; i++) {
	//	for (int j = ((i*i - i) / 2) + 1; j <= (i*i + i) / 2; j++) {
	//		cout << d[j] << ' ';
	//	}
	//	cout << '\n';
	//}


	cout << ans;

	return 0;
}