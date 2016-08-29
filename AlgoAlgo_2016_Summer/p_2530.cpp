#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<math.h>
#include<utility>
using namespace std;

int main() {
	int a, b, c,d;
	cin >> a >> b >> c>>d;
	
	c += d;
	int t = c / 60;
	c %= 60;

	b += t;
	int tt = b / 60;
	b %= 60;

	a += tt;
	a %= 24;

	cout << a << " " << b << " " << c << endl;

	return 0;
}