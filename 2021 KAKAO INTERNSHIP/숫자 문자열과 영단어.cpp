// 숫자 문자열과 영단어
// 간단한 구현 문제이다
// 문자열의 길이가 짧은 편이라 string의 erase를 사용해도 시간초과는 안날 것으로 보인다.

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    for (int i = 0; i < s.size(); ++i) {
        int next = 0;
        if (s[i] >= '0' && s[i] <= '9') next = (s[i] - '0');
        else {
            if (s[i] == 'z') next = 0, i += 3;
            else if (s[i] == 'o') next = 1, i += 2;
            else if (s[i] == 't') {
                if (s[i + 1] == 'w') next = 2, i += 2;
                else next = 3, i += 4;
            }
            else if (s[i] == 'f') {
                if (s[i + 1] == 'o') next = 4, i += 3;
                else next = 5, i += 3;
            }
            else if (s[i] == 's') {
                if (s[i + 1] == 'i') next = 6, i += 2;
                else next = 7, i += 4;
            }
            else if (s[i] == 'e') next = 8, i += 4;
            else if (s[i] == 'n') next = 9, i += 3;
        }
        answer = answer * 10 + next;
    }
    return answer;
}