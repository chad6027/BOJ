// 1149�� RGB �Ÿ�

// ���� DP�� ������ �ڵ��� �������� ���� ���� �����س��� ������ ���� �ð��� �ɷȴ�.
// ��ȭ���� Ȱ���� �����̰�,
// tmp_ans�� i��° ans���� ��� �������ִ� �뵵��� �����ϸ� �ȴ�.
// �� �ʿ��ϳİ� ����ٸ�, 
// ans[0] = min(tmp_ans[1], tmp_ans[2]) + RGB[3*i]; �̶� �� ���
// ans[0] = min(ans[1], ans[2]) + RGB[3*i]; �� ���ٸ�
// ���� �ٿ��� ans[1] �� ���� �� ������Ʈ �� ans[0]�� ���� �ּڰ��� ���ϱ� ������
// ��Ȯ�� ���� ������ �� ����.
// ��� d[3][3000] ���� ������ �迭�� ���� 3��¥�� ��ȭ������ �ڵ��� �����ѵ�
// �޸𸮸� �Ƴ���; �Ź� tmp_ans�� ������Ʈ���ִ� ����� ���ߴ�.
// �� ���� �ӵ��� ���Ѵٸ� ������ �迭�� ����ϴ� �� ���� ���̴�.


#include <iostream>
#include <algorithm>
using namespace std;
int RGB[3000];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < 3* N; i++) {
		cin >> RGB[i];
	}
	int tmp_ans[3] = { RGB[0], RGB[1], RGB[2] };
	int ans[3];
	for (int i = 1; i < N; i++) {
		ans[0] = min(tmp_ans[1], tmp_ans[2]) + RGB[3*i];
		ans[1] = min(tmp_ans[0], tmp_ans[2]) + RGB[3*i+1];
		ans[2] = min(tmp_ans[0], tmp_ans[1]) + RGB[3*i+2];
		tmp_ans[0] = ans[0];
		tmp_ans[1] = ans[1];
		tmp_ans[2] = ans[2];
	}
	cout << min(min(ans[0],ans[1]),ans[2]);
	return 0;
}