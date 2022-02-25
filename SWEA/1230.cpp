// 1230 암호문
#include<iostream>
#include<math.h>
#include<list>
#include<string.h>
#include<algorithm>
#include<iterator>
using namespace std;

list<int> li;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, numCmd, val, x, y;
		char cmd;
		li.clear();
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> val;
			li.push_back(val);
		}
		cin >> numCmd;
		while (numCmd--) {
			cin >> cmd;
			switch (cmd) {
			case 'I': {
				cin >> x >> y;
				auto it = li.begin();
				while (x--) { ++it; }
				while (y--) {
					cin >> val;
					li.insert(it, val);
				}
				break;
			}
			case 'D': {
				cin >> x >> y;
				auto it = li.begin();
				while (x--) { ++it; }
				++it;
				while (y--) {
					auto cur = it++;
					li.erase(cur);
				}
				break;
			}
			case 'A': {
				cin >> y;
				while (y--) {
					cin >> val;
					li.push_back(val);
				}
				break;
			}
			}
		}

		printf("#%d ", test_case);
		auto it = li.begin();
		for (int i = 0; i < 10; ++i, ++it) printf("%d ", *it);
		printf("\n");

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}