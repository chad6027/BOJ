#include <iostream>
#include <queue>
using namespace std;

int a[50];
int b[50];

int main() {

	priority_queue<pair<int, int>> pq;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		pq.push({ a[i], i });
	}

	while (!pq.empty()) {
		b[pq.top().second] = pq.size() - 1;
		pq.pop();
	}

	for (int i = 0; i < N; i++)
		cout << b[i] << ' ';



	return 0;
}