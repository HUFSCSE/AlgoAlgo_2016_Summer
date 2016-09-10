#include <iostream>
#include<cstdio>
#include<stack>
using namespace std;

int fibo[47];
int main() {
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; i <= 46; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	int n;
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		stack<int> s;
		while (num >0) {
			int i = 1;
			while (fibo[i] <= num) i += 1;
			i -= 1;
			//cout << fibo[i] << endl;
			s.push(fibo[i]);
			num -= fibo[i];
		}
		while (!s.empty()) {
			cout << s.top() << " ";
			s.pop();
		}
		cout << endl;
	}
	return 0;
}