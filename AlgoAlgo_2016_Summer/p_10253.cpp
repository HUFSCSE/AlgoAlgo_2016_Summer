#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<math.h>
#include<utility>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		int r = 0;
		cin >> a >> b;
		while (a > 1) {
			int t = b / a;
			while (b >= a*t)
				t += 1;
			a = (a*t) - b;
			b = b*t;
			for (int i = a; i > 1; i--)
			{
				if ((b%i == 0) && (a%i == 0))
				{
					a /= i;
					b /= i;
				}
			}
		}
		cout << b << endl;
	}
	return 0;
}