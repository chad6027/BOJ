//SWEA 10726 ������ ǥ��
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
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, m;
		cin >> n >> m;
		bitset<32> b(m);

		if (sovle(n, b)) printf("#%d ON\n", test_case);
		else printf("#%d OFF\n", test_case);

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}