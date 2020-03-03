// Q1158 요세푸스 문제

// 이중연결리스트로 풀 수 있는 문제이지만 큐를 이용하여 해결해보았다.
// 1부터 N까지 순서대로 enqueue를 한 다음
// k-1개를 dequeue를 하는 동시에 enqueue를 하게 되면 front에 k번째 수가 남는다.
// 따라서 front에 있는 수를 출력 후 dequeue만 해주고 queue가 빌 때까지 반복.

// 모두 알다시피 이중연결리스트, 큐 모두 삽입, 삭제 과정이 O(1)에 수행된다. 
// 이 문제 해결을 위해 이중연결리스트를 이용하면 삭제만 n번(O(n))이 일어나고,
// 큐를 이용하면 대략 K * n번의 삭제와, K * n번의 삽입이 일어나기 때문에 (K <= N을 생각했을 때, O(n^2)) 
// 64ms라는 훨씬 더 많은 시간이 소모되는 것을 알 수 있다.

 


#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	queue<int> q;
	
	int N, K;

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	cout << "<";

	while (!q.empty()) {

		for(int i = 1 ; i < K; i++){
			q.push(q.front());
			q.pop();
		}

		if (q.size() == 1)
			cout << q.front();
		else
			cout << q.front() << ", ";

		q.pop();
		
	}

	cout << ">";




	return 0;
}