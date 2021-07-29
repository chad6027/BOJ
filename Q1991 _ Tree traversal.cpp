// Q1991 _ 트리 순회

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = 2147483647;
const int MAX_N = 10e+5 + 1;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
class node {
public:
	node* lc;
	node* rc;
	char data;
	node(char ch) {
		lc = nullptr;
		rc = nullptr;
		data = ch;
	}
};

class bin_tree {
public:
	node* root;
	char arr[1001] = { 0, };

	bin_tree() {
		root = new node('A');
	}

	void push(char parent, char ch, bool left) {
		node* pNode = findNode(root, parent);
		node* newNode = new node(ch);
		if (left) pNode->lc = newNode;
		else pNode->rc = newNode;
	}
	node* findNode(node* cur, char target) {
		node* here = nullptr;
		if (cur->data == target) return cur;
		else {
			if (cur->lc != nullptr) here = findNode(cur->lc, target);
			if (here == nullptr && cur->rc != nullptr) here = findNode(cur->rc, target);
		}
		return here;
	}

	void preOrder(node* cur) {
		cout << cur->data;
		if (cur->lc != nullptr) preOrder(cur->lc);
		if (cur->rc != nullptr) preOrder(cur->rc);
	}

	void inOrder(node* cur) {
		if (cur->lc != nullptr) inOrder(cur->lc);
		cout << cur->data;
		if (cur->rc != nullptr) inOrder(cur->rc);
	}

	void postOrder(node* cur) {
		if (cur->lc != nullptr) postOrder(cur->lc);
		if (cur->rc != nullptr) postOrder(cur->rc);
		cout << cur->data;
	}

};




int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	bin_tree bt;
	int n;
	cin >> n;
	char alp[3];
	for (int i = 0; i < n; ++i) {
		cin >> alp[0] >> alp[1] >> alp[2];
		if (alp[1] != '.') bt.push(alp[0], alp[1], 1);
		if (alp[2] != '.') bt.push(alp[0], alp[2], 0);
	}
	bt.preOrder(bt.root);
	cout << '\n';
	bt.inOrder(bt.root);
	cout << '\n';
	bt.postOrder(bt.root);


	return 0;
}