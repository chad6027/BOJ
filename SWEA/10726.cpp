//SWEA 10726 이진수 표현
#include<iostream>
#include <bitset>
using namespace std;

bool sovle(int n, bitset<32> b) {
	for (int i = 0; i < n; ++i) if (!b[i]) return false;
	return true;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, m;
		cin >> n >> m;
		bitset<32> b(m);

		if (sovle(n, b)) printf("#%d ON\n", test_case);
		else printf("#%d OFF\n", test_case);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}