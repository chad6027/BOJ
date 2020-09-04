// Q1158 �似Ǫ�� ����

// ���߿��Ḯ��Ʈ�� Ǯ �� �ִ� ���������� ť�� �̿��Ͽ� �ذ��غ��Ҵ�.
// 1���� N���� ������� enqueue�� �� ����
// k-1���� dequeue�� �ϴ� ���ÿ� enqueue�� �ϰ� �Ǹ� front�� k��° ���� ���´�.
// ���� front�� �ִ� ���� ��� �� dequeue�� ���ְ� queue�� �� ������ �ݺ�.

// ��� �˴ٽ��� ���߿��Ḯ��Ʈ, ť ��� ����, ���� ������ O(1)�� ����ȴ�. 
// �� ���� �ذ��� ���� ���߿��Ḯ��Ʈ�� �̿��ϸ� ������ n��(O(n))�� �Ͼ��,
// ť�� �̿��ϸ� �뷫 K * n���� ������, K * n���� ������ �Ͼ�� ������ (K <= N�� �������� ��, O(n^2)) 
// 64ms��� �ξ� �� ���� �ð��� �Ҹ�Ǵ� ���� �� �� �ִ�.

 


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