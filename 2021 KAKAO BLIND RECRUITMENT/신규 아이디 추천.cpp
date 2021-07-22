// 신규 아이디 추천

// 완벽한 구현 문제.
// 하라는 대로만 잘 따라가보자.

#include <string>
#include <string.h>
#include <vector>

using namespace std;

bool checkChar(char ch) {
    if (ch == '.' || ch == '_' || ch == '-') return true;
    if (ch >= 'a' && ch <= 'z') return true;
    if (ch >= '0' && ch <= '9') return true;
    return false;

}
string solution(string new_id) {
    string answer = "";
    string& str = new_id;

    // step 1
    for (int i = 0; i < str.size(); ++i)
        if (str[i] >= 'A' && str[i] <= 'Z') str[i] += ('a' - 'A');

    //step 2
    for (int i = 0; i < str.size(); ++i) {
        if (!checkChar(str[i])) {
            str.erase(str.begin() + i);
            --i;
        }
    }
    // step 3
    for (int i = 1; i < str.size(); ++i) {
        if (str[i - 1] == '.' && str[i] == '.') {
            str.erase(str.begin() + i);
            --i;
        }
    }

    // step 4
    if (!str.empty() && str[0] == '.') str.erase(str.begin());
    if (!str.empty() && str.back() == '.') str.pop_back();

    // step 5
    if (str.empty())str.push_back('a');

    // step 6
    if (str.size() >= 16) {
        str = str.substr(0, 15);
        if (str.back() == '.') str.pop_back();
    }

    //step 7
    if (str.size() <= 2) {
        while (str.size() != 3) {
            str.push_back(str.back());
        }
    }

    return str;
}