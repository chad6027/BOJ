// 1149번 RGB 거리

// 아직 DP를 적용한 코딩에 적응하지 못해 답을 도출해내는 데까지 많은 시간이 걸렸다.
// 점화식을 활용한 문제이고,
// tmp_ans는 i번째 ans들을 잠시 저장해주는 용도라고 생각하면 된다.
// 왜 필요하냐고 물어본다면, 
// ans[0] = min(tmp_ans[1], tmp_ans[2]) + RGB[3*i]; 이란 식 대신
// ans[0] = min(ans[1], ans[2]) + RGB[3*i]; 을 쓴다면
// 다음 줄에서 ans[1] 을 구할 때 업데이트 된 ans[0]을 갖고 최솟값을 구하기 때문에
// 정확한 답을 도출할 수 없다.
// 사실 d[3][3000] 같은 이차원 배열을 쓰면 3줄짜리 점화식으로 코딩이 가능한데
// 메모리를 아끼고싶어서 매번 tmp_ans를 업데이트해주는 방식을 택했다.
// 더 빠른 속도를 원한다면 이차원 배열을 써야하는 게 맞을 것이다.


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