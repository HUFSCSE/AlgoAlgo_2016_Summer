#include <iostream>
using namespace std;

int d[10001];
int coin[100];
int main() {
	int n, money;
	cin >> n >> money;
	for (int i = 0; i < n; ++i)
		cin >> coin[i];
	d[0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = coin[i]; j <= money; ++j) {
			if (j - coin[i] >= 0)
				d[j] += d[j - coin[i]];
			/*
			cout << j << " " << i << " " 
				<< coin[i] << " " << j - coin[i]<<" "
				<<d[j]<< endl;
			*/
		}
	}
	cout << d[money] << endl;
	return 0;
}