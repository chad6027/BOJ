// Q1009 �л�ó��

// ���ڸ� ���ڵ鸸 �Ű���ָ� �ȴ�. ���������� �� ���� �����ϴ� ����� ������.. ���� Ǫ�� ��ÿ� �Ű���Ἥ �׳� �����ھҴ�..
#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T, a, b, ans;
	vector<int> v[10];
	v[0].push_back(10);
	
	v[1].push_back(1);
	
	v[2].push_back(6);
	v[2].push_back(2);
	v[2].push_back(4);
	v[2].push_back(8);
	
	v[3].push_back(1);
	v[3].push_back(3);
	v[3].push_back(9);
	v[3].push_back(7);
	
	v[4].push_back(6);
	v[4].push_back(4);
	
	v[5].push_back(5);
	
	v[6].push_back(6);

	v[7].push_back(1);
	v[7].push_back(7);
	v[7].push_back(9);
	v[7].push_back(3);
	
	v[8].push_back(6);
	v[8].push_back(8);
	v[8].push_back(4);
	v[8].push_back(2);
	
	v[9].push_back(1);
	v[9].push_back(9);
	
	

	cin >> T;
	while (T--) {
		cin >> a >> b;
		a %= 10;
		b %= v[a].size();

		cout << v[a][b] << '\n';
		
	}

	return 0;
}