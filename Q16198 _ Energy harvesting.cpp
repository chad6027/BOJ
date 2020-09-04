// Q16198 - 에너지 모으기

// next_permutation함수를 이용해 뽑는 순서를 미리 정하는 방법을 시도했지만, 순서를 정해주는 시간이 또 들기 때문에 포기.
// DFS로 해결하였다. 백트래킹으로 해결한다는데 아직 백트래킹에 대해서 정확히 모르기 때문에 공부 요망.


#include <iostream>
#include <algorithm>
using namespace std;

bool visit[10];
int ball[10];
int ans = 0;
int tmp = 0;
int N;

void DFS(int cur) {
	visit[cur] = true;

	// cur 앞뒤로 살아있는 숫자 확인 ( 아직 뽑히지 않은 숫자 확인 )
	int prev = cur, next = cur;
	for (int i = cur + 1; i < N; i++) {
		if (!visit[i]) {
			prev = i;
			break;
		}
	}
	for (int i = cur - 1; i >= 0; i--) {
		if (!visit[i]) {
			next = i;
			break;
		}
	}

	// 결과 계산
	tmp += ball[prev] * ball[next];

	// 처음부터 마지막까지 돌면서 내 자신이거나, 이미 뽑힌 숫자면 pass
	// 그렇지 않다면 DFS로 더 들어가보기
	for (int i = 1; i < N - 1; i++) {
		if (i == cur || visit[i]) {
			continue;
		}

		if (!visit[i]) {
			DFS(i);
		}
	}

	// 위 과정이 끝나면 tmp에 마지막 계산 결과가 들어있기 때문에, ans와 tmp의 최댓값 계산해서 ans에 저장
	ans = max(ans, tmp);
	// return 되기 전에 이 함수에서 계산한 값을 빼줘 이전 tmp 값으로 돌려주고, visit도 false로 해서 다시 돌아올 수 있게 만들어준다.
	tmp -= ball[prev] * ball[next];
	visit[cur] = false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> ball[i];
	}

	//처음과 마지막은 선택이 안되므로 1 ~ N-2 까지 DFS 돌기
	for (int i = 1; i < N - 1; i++) {
		tmp = 0;
		DFS(i);
	}

	cout << ans << '\n';

	return 0;
}