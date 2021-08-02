// 표 편집
// 처음에 deque로 구현해서 시간초과
// 세그먼트 트리로 n * (log n) * (log n)으로 해보려고 했는데 역시 효율성에서 시간초과
// 세그먼트 트리를 비재귀로 구현하면 TLE에서 벗어날 수 있다고해서 구글링해봤는데 아직 잘모르겠다; 팬 윅 트리도 잘모르는데..
// 그래서 list로 다시 구현했다.

// 사실 바보 같은 생각 하나를 했었는데 deque의 삽입 삭제가 막연하게 O(1)인 줄 알고 있었다 (너무 자유롭게 되길래;; 이전까지 deque가 미친 컨테이너인 줄 알았다.).
// 그래서 이번에 TLE에 걸리는 걸 보고 공식 레퍼런스를 보니까 벡터 기반이라 최악이 linear time이라고 명시되어있더라

// 결국 생각해낸 것이 list로 구현하고 내가 원하는 list 원소에 O(1)에 접근할 수 있게 1,000,001개짜리 iterator 하나 flex했다.
// 1,000,001개짜리 iterator들은 자기 자신의 index와 같은 값을 갖고 있는 list 원소를 가르킨다.

// 삭제는 문제에서 시키는 대로 해주자. 그리고 stack에는 삭제되는 숫자와 삭제된 후에 가르키고 있는 숫자를 넣어주자.

// 복구는 stack에 가장 위에 있는걸 꺼내와서 가르키고 있던 숫자 자리에 삭제됐던 숫자를 insert 해주면된다.
// 이 때 예외사항 하나가 있는데, 삭제된 숫자보다 삭제된 후에 가르켜지는 숫자가 작으면 삭제된 숫자는 가장 마지막에 있었던 것이었기 때문에 가장 뒤쪽에 넣어주면 된다.


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