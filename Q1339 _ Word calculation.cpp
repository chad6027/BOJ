#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <utility>
using namespace std;

bool cmp(const pair<int, char> p1, const pair<int, char> p2) {
	return p1.first > p2.first ? 1 : 0;
}

int main() {
	vector<pair<int, char>> p;
	vector<string> vs;
	string s;
	bool exist;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (p.empty()) {
				p.push_back({ pow(10, s.size() - j - 1), s[j] });
			}
			else {
				exist = false;
				for (int k = 0; k < p.size(); k++) {
					if (s[j] == p[k].second) {
						p[k].first += pow(10, s.size() - j - 1);
						exist = true;
						break;
					}
				}
				if (!exist) {
					p.push_back({ pow(10, s.size() - j - 1), s[j] });
				}
			}
		}
		vs.push_back(s);
	}
	int ans = 0;
	sort(p.begin(), p.end(), cmp);
	for (int i = 0; i < p.size(); i++) {
		ans += p[i].first * (9 - i);
	}
	cout << ans << '\n';

	return 0;
}