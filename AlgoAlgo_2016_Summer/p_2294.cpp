#include <iostream>
using namespace std;
#define max 10000000
int d[10001];
int coin[100];
int main() {
	int n, money;
	cin >> n >> money;
	for (int i = 0; i < n; ++i)
		cin >> coin[i];
	d[0] = 0;
	for (int i = 1; i <= money; ++i) {
		if (i == coin[i])
			d[i] = 1;
		else
			d[i] = max;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = coin[i]; j <= money; ++j) {
			//cout << j << " " << j-coin[i] << " " << d[j] << " " << d[j - coin[i]]+1 << " ";
			if (d[j] > d[j - coin[i]] + 1)
				d[j] = d[j - coin[i]] + 1;
			//cout << d[j] << endl;
			/*
			cout << j << " " << i << " "
			<< coin[i] << " " << j - coin[i]<<" "
			<< d[j-coin[i]]<<" "<<d[j]<< endl;
			*/
		}
	}
	if (d[money] == max)
		cout << -1 << endl;
	else
		cout << d[money] << endl;
	return 0;
}