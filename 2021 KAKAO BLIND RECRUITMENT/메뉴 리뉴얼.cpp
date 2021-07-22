// �޴� ������

// ���� Ž�� �����̴�.
// Ǯ�� ���� TLE�� �ɸ��� ��¦ �̸Ծ�����, ������ �������� ��ź�ϰ� Ǯ�ȴ�.
// n�� 30, ������ 50���϶�� ����Ž������ �����غ���.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>

using namespace std;

bool alpha[20][26] = { 0, }; // �� �ڽ��� �޴� ����
bool allAlpha[26] = { 0, }; // ��� �ڽ��� �����Ͽ� �ֹ��� �޴�
int n, k;
map<string, int> mp[11];
string tmp = "";
void DFS(int cur, int selected) {

    if (selected == k) {
        int cnt = 0;
        // ���õ� �޴����� �ֹ��� �ο��� Ȯ��.
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
        // �θ��� ���� ����� ��Ų ���̶�� ����
        if (cnt < 2) return;

        if (mp[k].empty()) mp[k][tmp] = cnt;
        else {
            // mp���� �ֹ��� Ƚ���� ���� �޴������� ���ִµ�, 
            // ���� ���� ���õ� �޴������� �� ���� �ֹ��Ǿ��ٸ�
            // ������ �ִ� �޴����� ������ ���� �߰�
            if (mp[k].begin()->second < cnt) {
                mp[k].clear();
                mp[k][tmp] = cnt;
            }
            // �ֹ��� Ƚ���� ���ٸ� �� �߰�
            else if (mp[k].begin()->second == cnt) {
                mp[k][tmp] = cnt;
            }
        }
        return;
    }
    // k���� �����ϴ� ����
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
        //DFS�� �̿��Ͽ� ����Ž��
        for (int j = 0; j < 26; ++j) {
            if (allAlpha[j]) {
                tmp = (char)('A' + j);
                DFS(j, 1);
            }
        }
        // ���õ� k���� �޴� ������ answer�� �ٽ� ����
        for (auto it = mp[k].begin(); it != mp[k].end(); ++it) {
            answer.push_back(it->first);
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}