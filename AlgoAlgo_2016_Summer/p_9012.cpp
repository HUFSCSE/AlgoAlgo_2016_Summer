#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n--) {
	string str;
	cin >> str;
	bool check = true;
	stack<char> s;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == '(') 
			s.push(c);
		else if (c == ')') {
			if (!s.empty() && s.top() == '(')
				s.pop();
			else {
				check = false;
				break;
			}
		}
	}
	if (s.empty() && check)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	}
	return 0;
}