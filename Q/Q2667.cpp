#include <iostream>
#include <list>
#include <iterator>
using namespace std;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1 , 0, 0 };
bool a[25][25];
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