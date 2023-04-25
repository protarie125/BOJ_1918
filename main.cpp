#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	string s;
	cin >> s;

	auto op = stack<char>{};
	for (const auto& c : s) {
		if ('A' <= c && c <= 'Z') {
			cout << c;
			continue;
		}

		if (op.empty()) {
			op.push(c);
			continue;
		}

		if ('(' == c) {
			op.push(c);
			continue;
		}

		if (')' == c) {
			while ('(' != op.top()) {
				cout << op.top();
				op.pop();
			}

			op.pop();
			continue;
		}

		if ('*' == c || '/' == c) {
			while (!op.empty() &&
				('*' == op.top() || '/' == op.top())) {
				cout << op.top();
				op.pop();
			}

			op.push(c);
			continue;
		}

		if ('+' == c || '-' == c) {
			while (!op.empty() &&
				('*' == op.top() || '/' == op.top() ||
					'+' == op.top() || '-' == op.top())) {
				cout << op.top();
				op.pop();
			}

			op.push(c);
		}
	}

	while (!op.empty()) {
		cout << op.top();
		op.pop();
	}

	return 0;
}