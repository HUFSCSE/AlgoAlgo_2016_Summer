#include <iostream>     
#include <algorithm>   
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> myints;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		myints.push_back(t);
	}
	bool c = false;
	while (prev_permutation(myints.begin(), myints.end())) {
		for (int i = 0; i < n; i++)
			cout << myints[i] << " ";
		c = true;
		break;
	}
	if (!c)
		cout << -1 << endl;
	return 0;
}