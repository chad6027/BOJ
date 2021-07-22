// 메뉴 리뉴얼

// 완전 탐색 문제이다.
// 풀기 전에 TLE에 걸릴까 살짝 겁먹었지만, 구현에 성공하자 평탄하게 풀렸다.
// n이 30, 많으면 50이하라면 완전탐색으로 시작해보자.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>

using namespace std;

bool alpha[20][26] = { 0, }; // 한 코스당 메뉴 구성
bool allAlpha[26] = { 0, }; // 모든 코스를 종합하여 주문된 메뉴
int n, k;
map<string, int> mp[11];
string tmp = "";
void DFS(int cur, int selected) {

    if (selected == k) {
        int cnt = 0;
        // 선택된 메뉴들을 주문한 인원을 확인.
        for (int i = 0; i < n; ++i) {
            bool no = false;
            for (int j = 0; j < k; ++j) {
                if (!alpha[i][tmp[j] - 'A']) {
                    no = true;
                    break;
                }
            }
            if (!no) cnt++;
        }
        // 두명보다 적은 사람이 시킨 것이라면 무시
        if (cnt < 2) return;

        if (mp[k].empty()) mp[k][tmp] = cnt;
        else {
            // mp에는 주문된 횟수가 같은 메뉴조합이 모여있는데, 
            // 만약 지금 선택된 메뉴조합이 더 많이 주문되었다면
            // 기존에 있던 메뉴들을 날리고 새로 추가
            if (mp[k].begin()->second < cnt) {
                mp[k].clear();
                mp[k][tmp] = cnt;
            }
            // 주문된 횟수가 같다면 답 추가
            else if (mp[k].begin()->second == cnt) {
                mp[k][tmp] = cnt;
            }
        }
        return;
    }
    // k개를 선택하는 구성
    for (int next = cur + 1; next < 26; ++next) {
        if (allAlpha[next]) {
            tmp += (char)('A' + next);
            DFS(next, selected + 1);
            tmp.pop_back();
        }
    }
}


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    n = orders.size();
    for (int i = 0; i < orders.size(); ++i) {
        string& str = orders[i];
        for (int j = 0; j < str.size(); ++j) {
            alpha[i][str[j] - 'A'] = true;
            allAlpha[str[j] - 'A'] = true;
        }
    }



    int answer_sz = 0;
    for (int i = 0; i < course.size(); ++i) {
        k = course[i];
        //DFS를 이용하여 완전탐색
        for (int j = 0; j < 26; ++j) {
            if (allAlpha[j]) {
                tmp = (char)('A' + j);
                DFS(j, 1);
            }
        }
        // 선택된 k개의 메뉴 구성을 answer에 다시 저장
        for (auto it = mp[k].begin(); it != mp[k].end(); ++it) {
            answer.push_back(it->first);
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}