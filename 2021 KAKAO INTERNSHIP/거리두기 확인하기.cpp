// �Ÿ��α� Ȯ���ϱ�
//
// �Ÿ��� 2�� �� �������� �ʴ� ����
// P X P    P   P X     X P     
//          X   X P     P X     
//          P
// �̰͸� Ȯ�����ָ� �ȴ�.
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

char room[5][5][5];
vector<pair<int, int>> person[5];
bool checkPartition(int, pair<int, int>&, pair<int, int>&);

// �Ÿ� ���
int calDist(pair<int, int>& p1, pair<int, int>& p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}
// �� ���ǿ� �ִ� ����鰣�� �Ÿ� Ȯ��
bool checkDist(int cur) {
    if (person[cur].size() == 0) return true;

    sort(person[cur].begin(), person[cur].end());

    for (int i = 0; i < person[cur].size(); ++i) {
        for (int j = i + 1; j < person[cur].size(); ++j) {
            int dist = calDist(person[cur][i], person[cur][j]);
            // �Ÿ��� 1�̸� �濪��Ģ ����
            if (dist == 1) return false;
            // �Ÿ��� 2�̸� �濪��Ģ �����ߴ��� Ȯ��
            else if (dist == 2) {
                if (!checkPartition(cur, person[cur][i], person[cur][j]))
                    return false;
            }
        }
    }
    // ���� for���� �������Դٸ� �濪��Ģ�� ��Ų ���̴�.
    return true;
}

bool checkPartition(int cur_room, pair<int, int>& p1, pair<int, int>& p2) {
    // P X P
    if (p1.first == p2.first) {
        if (room[cur_room][p1.first][p1.second + 1] == 'X') return true;
    }
    // P
    // X
    // P
    else if (p1.second == p2.second) {
        if (room[cur_room][p1.first + 1][p1.second] == 'X') return true;
    }
    else {
        // P X 
        // X P  
        if (p1.second < p2.second) {
            if (room[cur_room][p1.first][p1.second + 1] == 'X'
                &&
                room[cur_room][p2.first][p2.second - 1] == 'X'
                )
                return true;
        }
        // X P
        // P X
        else {
            if (room[cur_room][p1.first][p1.second - 1] == 'X'
                &&
                room[cur_room][p2.first][p2.second + 1] == 'X'
                )
                return true;
        }
    }

    return false;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) {
                room[i][j][k] = places[i][j][k];
                if (room[i][j][k] == 'P') person[i].push_back({ j, k });
            }
        }
    }
    for (int i = 0; i < 5; ++i) {
        if (checkDist(i)) answer.push_back(1);
        else answer.push_back(0);
    }

    return answer;
}