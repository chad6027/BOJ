// 거리두기 확인하기
//
// 거리가 2일 때 위반하지 않는 경우는
// P X P    P   P X     X P     
//          X   X P     P X     
//          P
// 이것만 확인해주면 된다.
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

// 거리 계산
int calDist(pair<int, int>& p1, pair<int, int>& p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}
// 각 대기실에 있는 사람들간의 거리 확인
bool checkDist(int cur) {
    if (person[cur].size() == 0) return true;

    sort(person[cur].begin(), person[cur].end());

    for (int i = 0; i < person[cur].size(); ++i) {
        for (int j = i + 1; j < person[cur].size(); ++j) {
            int dist = calDist(person[cur][i], person[cur][j]);
            // 거리가 1이면 방역수칙 위반
            if (dist == 1) return false;
            // 거리가 2이면 방역수칙 위반했는지 확인
            else if (dist == 2) {
                if (!checkPartition(cur, person[cur][i], person[cur][j]))
                    return false;
            }
        }
    }
    // 이중 for문을 빠져나왔다면 방역수칙을 지킨 것이다.
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