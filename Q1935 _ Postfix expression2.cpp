//1935 후위 표기식2

// float으로 선언했다가 오답처리된 문제.
// double이 float보다 2배정도 더 정확하기 때문에 float으로 선언하면 틀리는 것으로 추측
// 영대문자에 대응하는 값이 사전순대로 입력되기 때문에 값을 저장하는 배열에 선언하고
// ( x - 'A') 를 해주면 A -> 0 , B -> 1 , ... 식으로 자신의 값을 저장한 배열의 인덱스가 된다.
// 따라서 후위 표기식을 앞에서부터 하나씩 검사할 때 
// 영대문자이면 스택에는 그에 해당하는 값을 push해주고 
// 그렇지 않으면 +, -, *, / 이기 때문에 각 케이스마다 적절한 값을 구하고 그 값을 다시 스택에 push한다.
// 주의할 점은 AB+ 을 계산한다고 생각할 때, 스택에서 pop이 두번 이루어진 후 새로운 값이 push 된다는 것이다.

// 모든 과정이 끝나고 스택에 남아있는 값이 답이 된다.


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

	int* val = new int[N]; //ABC...의 값을 저장하는 배열
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