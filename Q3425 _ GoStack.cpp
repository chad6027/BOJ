// 출력 형식이 잘못되었습니다 라는 에러메세지는 처음 받아봐서 당황했던 문제다.
// 한 프로그램 수행이 될 때마다 마지막에 빈 라인 하나를 출력해주었어야 하는데 
// 문제를 대충 읽다가 그냥 지나쳐버린게 화근이었다.
// 다시 한번 상기하자. 문제는 항상 제대로 읽자.

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = 2147483647;
const int MAX = 10e+8;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

class stk {
public:
	vector<pair<int, int>> cmdList;
	ll arr[1010] = { 0, };
	int cur = 0;
	bool setcmd() {
		string str;
		int x;
		int cmd = -1;
		while (true) {
			cin >> str;
			if (str[0] == 'Q') return false;

			if (str == "NUM") { cmd = 0; cin >> x; }
			else if (str == "POP") cmd = 1;
			else if (str == "INV") cmd = 2;
			else if (str == "DUP") cmd = 3;
			else if (str == "SWP") cmd = 4;
			else if (str == "ADD") cmd = 5;
			else if (str == "SUB") cmd = 6;
			else if (str == "MUL") cmd = 7;
			else if (str == "DIV") cmd = 8;
			else if (str == "MOD") cmd = 9;
			else if (str == "END") return true;

			cmdList.push_back({ cmd, x });
		}
	}
	void executeCmd(int start) {
		num(start);
		for (pair<int, int> p : cmdList) {
			int cmd = p.first;
			bool isWorked = true;
			if (cmd == 0) num(p.second);
			else if (cmd == 1) isWorked = pop();
			else if (cmd == 2) inv();
			else if (cmd == 3) dup();
			else if (cmd == 4) isWorked = swp();
			else if (cmd == 5) isWorked = add();
			else if (cmd == 6) isWorked = sub();
			else if (cmd == 7) isWorked = mul();
			else if (cmd == 8) isWorked = div();
			else if (cmd == 9) isWorked = mod();
			if (!isWorked) {
				cout << "ERROR\n";
				return;
			}
		}
		if (cur == 1) cout << arr[cur - 1] << '\n';
		else cout << "ERROR" << '\n';
	}

	void num(int x) {
		arr[cur++] = x;
	}
	bool pop() {
		if (cur <= 0) {
			return false;
		}
		else {
			--cur;
			return true;
		}
	}
	void inv() {
		arr[cur - 1] *= -1;
	}
	void dup() {
		arr[cur] = arr[cur - 1];
		++cur;
	}
	bool swp() {
		if (cur < 2) {
			return false;
		}
		else {
			swap(arr[cur - 1], arr[cur - 2]);
			return true;
		}
	}
	bool add() {
		if (cur < 2) {
			return false;
		}
		else {
			arr[cur - 2] += arr[cur - 1];
			--cur;
			if (abs(arr[cur - 1]) <= MAX) return true;
			else return false;
		}
	}
	bool sub() {
		if (cur < 2) {
			return false;
		}
		else {
			arr[cur - 2] -= arr[cur - 1];
			--cur;
			if (abs(arr[cur - 1]) <= MAX) return true;
			else return false;
		}
	}
	bool mul() {
		if (cur < 2) {
			return false;
		}
		else {
			arr[cur - 2] *= arr[cur - 1];
			--cur;
			if (abs(arr[cur - 1]) <= MAX) return true;
			else return false;
		}
	}
	bool div() {
		if (cur < 2) {
			return false;
		}
		else {
			if (arr[cur - 1] == 0) return false;

			ll dividend = abs(arr[cur - 2]);
			ll divisor = abs(arr[cur - 1]);
			ll result = dividend / divisor;
			if (arr[cur - 2] * arr[cur - 1] < 0) result *= -1;
			arr[cur - 2] = result;
			--cur;
			return true;
		}
	}
	bool mod() {
		if (cur < 2) {
			return false;
		}
		else {
			if (arr[cur - 1] == 0) return false;

			ll dividend = abs(arr[cur - 2]);
			ll divisor = abs(arr[cur - 1]);
			ll result = dividend % divisor;
			if (arr[cur - 2] < 0) result *= -1;
			arr[cur - 2] = result;
			--cur;
			return true;
		}
	}
	void clear() {
		cur = 0;
		cmdList.clear();
	}

	void clearStack() {
		cur = 0;
	}

};


int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	stk s;
	while (s.setcmd()) {
		int n, integer;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> integer;
			s.executeCmd(integer);
			s.clearStack();
		}
		s.clear();
		cout << endl;
	}
	return 0;
}