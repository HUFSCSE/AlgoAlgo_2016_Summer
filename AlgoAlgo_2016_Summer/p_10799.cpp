#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main() {
	string str;
	cin >> str;
	int cnt = 0;
	stack<char> s;
	char pre = NULL;
	for (int i = 0; i<str.size(); i++) {
		if (str[i] == '(') {
			s.push(str[i]);
			pre = str[i];
		}
		else {
			s.pop();
			if (pre == '(') {
				cnt += s.size();
				pre = ')';
			}
			else {
				cnt += 1;
				pre = ')';
			}
		}
	}
	cout << cnt << endl;
	return 0;
}