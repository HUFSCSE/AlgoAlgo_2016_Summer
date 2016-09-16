#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
using namespace std;
int arr[31][31];
string a, b;
int i;
void go(stack<int> &s, int &i) {
	if (i >= a.size())
		return;
	stack<int> temp;
	int to = s.top();
	temp.push(s.top());
	bool c = false;
	while (a[i] != ')' && i<a.size()) {
		if (a[i] >= 'A' && a[i] <= 'Z' + 1) {
			if (c) {
				int t = a[i] - 'A';
				while (temp.empty() != to) {
					arr[temp.top()][t] = 1;
					temp.pop();
				}
				temp.push(t);
				//cout << temp.top() << " ";
				i++;
			}
			else {
				int t = a[i] - 'A';
				arr[s.top()][t] = 1;
				temp.push(t);
				//cout << temp.top() << " ";
				i++;
				c = true;
			}
		}
		else if (a[i] == '|') {
			c = false;
			i++;
		}
		else if (a[i] == '(') {
			i += 1;
			go(temp, i);
		}
		else if (a[i] == '_') {
			a[i] = 'Z' + 1;
		}
	}
	if(a[i] == '_')
		a[i] = 'Z' + 1;
	s.pop();
	while (temp.top() != to) {
		s.push(temp.top());
		cout << (char)('A' + s.top()) << " ";
		temp.pop();
	}
	i += 1;
}


bool travel(int start, int end) {
	if (end >= b.size())
		return true;
	int start2 = b[start] - 'A';
	int end2 = b[end] - 'A';
	cout << b[start] << " " << b[end] << " " << arr[start2][end2] << endl;
	if (arr[start2][end2])
		return 1 && travel(end, end + 1);
	else
		return false;
}
int main() {
	/*
	1
A(BCDEFG(H|J)K|L)M
ABCDEFGJKM
	*/
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		cin >> a >> b;
		stack<int> s;

		for (i = 0; i < a.size();) {
			//cout << i;
			if (a[i] >= 'A' && a[i] <= 'Z' + 1) {
				int t = a[i] - 'A';
				while (!s.empty()) {
					arr[s.top()][t] = 1;
					s.pop();
				}
				s.push(t);
				cout << (char)('A' + s.top()) << " ";
				i++;
			}
			else if (a[i] == '(') {
				i += 1;
				go(s, i);
			}
			else if (a[i] == '_') {
				a[i] = 'Z' + 1;
			}
			else
				i += 1;
		}

		/*///////
		for (int ii = 0; ii < 27; ii++) {
		for (int j = 0; j < 27; j++)
		cout << arr[ii][j] << " ";
		cout << endl;
		}
		///////*/
		char temp = NULL;
		for (int j = 0; j < b.size(); j++) {
			int cc = 0;
			for (int tt = 0; tt < 26; tt++)
				if (arr[b[j] - 'A'][tt] || arr[tt][b[j] - 'A'])
					cc += 1;
			if (cc == 0) {
				temp = b[j];
				b[j] = 'Z' + 1;
				break;
			}
		}
		bool reseult = travel(0, 1);
		if (reseult && (temp == NULL))
			printf("_\n");
		else if (reseult && (temp != NULL))
			printf("%c\n", temp);
		else
			printf("!\n");

		for (int ii = 0; ii < 31; ii++) 
			for (int j = 0; j < 31; j++)
				arr[ii][j] = 0;
	}
	return 0;
}