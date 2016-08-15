#include<iostream>
using namespace std;
int arr[100];
int d[10001];
int main() {
	for (int i = 0; i < 10001; i++)
		d[i] = 10000000;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] <= 10000)
			d[arr[i]] = 1;
	}
	d[0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = arr[i]; j <= m; j++)
			if (j - arr[i] >= 0 && d[j] > d[j - arr[i]] + 1) {
				d[j] = d[j - arr[i]] + 1;
				cout << j << " " << i << " "
					<< arr[i] << " " << j - arr[i] << " "
					<< d[j - arr[i]] << " " << d[j] << endl;
			}
	if (d[m] == 10000000)
		cout << -1 << endl;
	else
		cout << d[m] << endl;
	return 0;
}