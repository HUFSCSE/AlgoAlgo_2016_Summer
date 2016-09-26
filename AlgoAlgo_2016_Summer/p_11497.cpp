#include<iostream>
#include<vector>
#include <string>
#include<algorithm>
using namespace std;

char z[101];
int main() {
	int n;
	cin >> n;
	while (n--) {
		int ret = -1;
		vector<int> k;
		int a;
		cin >> a;
		for (int i = 0; i<a; ++i) {
			int b;
			cin >> b;
			k.push_back(b);
		}
		sort(k.begin(), k.end());

		for (int i = 0; i + 2<a; i = i + 2) 
			ret = max(ret, abs(k[i] - k[i + 2]));
		for (int i = 1; i + 2<a; i = i + 2)
			ret = max(ret, abs(k[i] - k[i + 2]));

		ret = max(ret, abs(k[0] - k[1]));
		cout << ret << endl;
	}
	return 0;
}