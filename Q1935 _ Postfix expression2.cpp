//1935 ���� ǥ���2

// float���� �����ߴٰ� ����ó���� ����.
// double�� float���� 2������ �� ��Ȯ�ϱ� ������ float���� �����ϸ� Ʋ���� ������ ����
// ���빮�ڿ� �����ϴ� ���� ��������� �ԷµǱ� ������ ���� �����ϴ� �迭�� �����ϰ�
// ( x - 'A') �� ���ָ� A -> 0 , B -> 1 , ... ������ �ڽ��� ���� ������ �迭�� �ε����� �ȴ�.
// ���� ���� ǥ����� �տ������� �ϳ��� �˻��� �� 
// ���빮���̸� ���ÿ��� �׿� �ش��ϴ� ���� push���ְ� 
// �׷��� ������ +, -, *, / �̱� ������ �� ���̽����� ������ ���� ���ϰ� �� ���� �ٽ� ���ÿ� push�Ѵ�.
// ������ ���� AB+ �� ����Ѵٰ� ������ ��, ���ÿ��� pop�� �ι� �̷���� �� ���ο� ���� push �ȴٴ� ���̴�.

// ��� ������ ������ ���ÿ� �����ִ� ���� ���� �ȴ�.


#include <iostream>
#include <stack>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	int N;
	double tmp;
	string s;

	stack<double> stk;
	cin >> N;

	int* val = new int[N]; //ABC...�� ���� �����ϴ� �迭
	cin >> s;

	for (int i = 0; i < N; i++) {
		cin >> val[i];
	}
	
	for (int i = 0; i < s.size(); i++) {
		if (s[i] <= 'Z' && s[i] >= 'A') {
			stk.push((double)val[s[i] - 'A']);
		}
		else {
			tmp = stk.top();
			stk.pop();
			switch (s[i]) {
				case '+':
					tmp += stk.top();
					break;
				case '-':
					tmp = stk.top() - tmp;
					break;
				case '*':
					tmp *= stk.top();
					break;
				case '/':
					tmp = stk.top() / tmp;
					break;
			}
			stk.pop();
			stk.push(tmp);
		}
	}

	cout << fixed << setprecision(2) << stk.top();

	delete val;

	return 0;
}