// ǥ ����
// ó���� deque�� �����ؼ� �ð��ʰ�
// ���׸�Ʈ Ʈ���� n * (log n) * (log n)���� �غ����� �ߴµ� ���� ȿ�������� �ð��ʰ�
// ���׸�Ʈ Ʈ���� ����ͷ� �����ϸ� TLE���� ��� �� �ִٰ��ؼ� ���۸��غôµ� ���� �߸𸣰ڴ�; �� �� Ʈ���� �߸𸣴µ�..
// �׷��� list�� �ٽ� �����ߴ�.

// ��� �ٺ� ���� ���� �ϳ��� �߾��µ� deque�� ���� ������ �����ϰ� O(1)�� �� �˰� �־��� (�ʹ� �����Ӱ� �Ǳ淡;; �������� deque�� ��ģ �����̳��� �� �˾Ҵ�.).
// �׷��� �̹��� TLE�� �ɸ��� �� ���� ���� ���۷����� ���ϱ� ���� ����̶� �־��� linear time�̶�� ��õǾ��ִ���

// �ᱹ �����س� ���� list�� �����ϰ� ���� ���ϴ� list ���ҿ� O(1)�� ������ �� �ְ� 1,000,001��¥�� iterator �ϳ� flex�ߴ�.
// 1,000,001��¥�� iterator���� �ڱ� �ڽ��� index�� ���� ���� ���� �ִ� list ���Ҹ� ����Ų��.

// ������ �������� ��Ű�� ��� ������. �׸��� stack���� �����Ǵ� ���ڿ� ������ �Ŀ� ����Ű�� �ִ� ���ڸ� �־�����.

// ������ stack�� ���� ���� �ִ°� �����ͼ� ����Ű�� �ִ� ���� �ڸ��� �����ƴ� ���ڸ� insert ���ָ�ȴ�.
// �� �� ���ܻ��� �ϳ��� �ִµ�, ������ ���ں��� ������ �Ŀ� ���������� ���ڰ� ������ ������ ���ڴ� ���� �������� �־��� ���̾��� ������ ���� ���ʿ� �־��ָ� �ȴ�.


#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iterator>
#include <list>

using namespace std;

bool isRemoved[1000001] = { 0, };
list<int>::iterator l_it[1000001];
list<int> li;
list<int>::iterator cur;

stack<pair<int, int>> stk;
int tmp = 0;

void move() {
    if (tmp > 0) while (tmp--) { cur++; }
    else if (tmp < 0) while (tmp++) { cur--; }

    tmp = 0;
}

void U(int x) {
    tmp -= x;
}

void D(int x) {
    tmp += x;
}

void C() {
    move();

    list<int>::iterator er = cur;
    int erase_num = *er;
    cur++;

    li.erase(er);

    if (cur == li.end()) --cur;

    isRemoved[erase_num] = true;
    stk.push({ erase_num, *cur });
}

void Z() {
    move();

    int erase_num = stk.top().first;
    int next = stk.top().second;
    stk.pop();

    if (erase_num < next) {
        li.insert(l_it[next], erase_num);
        auto tmp = l_it[next];
        tmp--;
        l_it[erase_num] = tmp;
    }
    else {
        li.insert(li.end(), erase_num);
        l_it[erase_num] = --li.end();
    }

    isRemoved[erase_num] = false;
}


string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    li.resize(n);
    int i = 0;
    for (auto it = li.begin(); it != li.end(); ++it, ++i) {
        *it = i;
        l_it[i] = it;
    }

    cur = l_it[k];


    for (int i = 0; i < cmd.size(); ++i) {
        char ch = cmd[i][0];
        if (ch == 'U' || ch == 'D') {
            int x = 0;
            for (int j = 2; j < cmd[i].size(); ++j) x = x * 10 + (cmd[i][j] - '0');

            if (ch == 'U') U(x);
            else D(x);
        }
        else if (ch == 'C') C();
        else if (ch == 'Z') Z();
    }

    for (int i = 0; i < n; ++i) {
        if (isRemoved[i]) answer += 'X';
        else answer += 'O';
    }

    return answer;
}