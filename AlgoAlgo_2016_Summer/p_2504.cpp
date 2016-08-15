#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> s;
string str;
int sum = 0;
int mul = 1;
int main() {
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			mul *= 2;
			s.push(str[i]);
			if (str[i + 1] == ')') sum += mul;
		}
		else if (str[i] == '[') {
			mul *= 3;
			s.push(str[i]);
			if (str[i + 1] == ']')sum += mul;
		}
		else if (!s.empty() && str[i] == ')') {
			mul /= 2;
			s.pop();
		}
		else if (!s.empty() && str[i] == ']') {
			mul /= 3;
			s.pop();
		}
	}

	if (s.empty()) {
		cout << sum;
	}
	else {
		cout << 0;
	}
	return 0;
}