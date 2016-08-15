#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<math.h>
#include<utility>
using namespace std;
int arr[101][101];
int d[101][101];
bool c[101][101];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	for (int t = 0; t < n; t++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (arr[i][t] == 1 && arr[t][j] == 1) arr[i][j] = 1;
			}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	return 0;
}