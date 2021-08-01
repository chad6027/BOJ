// ���� ���ڿ��� ���ܾ�
// ������ ���� �����̴�
// ���ڿ��� ���̰� ª�� ���̶� string�� erase�� ����ص� �ð��ʰ��� �ȳ� ������ ���δ�.

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