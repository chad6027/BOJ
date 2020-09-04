// Q2667 단지번호붙이기

// DFS로 해결하는 문제라는걸 알면 쉽게 풀리는 문제이다.
// 쉽게 풀리는 문제라 딱히 적을 내용은 없다.
// 아, 다른 사람들은 어떻게 해결했는지 보다가 상하좌우를 검사할 때
// dx, dy 배열을 만들어서 for문으로 한번에 상하좌우를 검사하는 방법을 보고
// 코드도 더 깔끔해보이고 효율적인 것 같아 보여 같은 방식으로 고쳤다.
// 또, 단지 내 집의 수를 어떻게 저장할까 고민해봤는데 벡터나 리스트 모두 가능할 것 같아
// 최근에 사용해보지 못한 list와 iterator를 사용해봤다.


#include <iostream>
#include <list>
#include <iterator>
using namespace std;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1 , 0, 0 };
int a[25][25];
int N;
bool visited[25][25] = { 0 , };

int DFS(int cur_h, int cur_v) {

	int cou = 1;
	
	visited[cur_h][cur_v] = true;
	
	if (a[cur_h][cur_v] == 0) {
		return 0;
	}

	for (int d = 0; d < 4; d++) {
		int nh = cur_h + dx[d];
		int nv = cur_v + dy[d];

		if (nh >= 0 && nv >= 0 && nh < N && nv < N) {
			if (!visited[nh][nv])
				cou += DFS(nh, nv);
		}
	}

	return cou;

}



int main() {
	list<int> li;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%1d", &a[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] == 1 && !visited[i][j]) {
				li.push_back(DFS(i , j));
			}
		}
	}

	li.sort();
	cout << li.size() << '\n';
	for (list<int>::iterator it = li.begin(); it != li.end(); it++) {
		cout << *it << '\n';
	}

	return 0;
}