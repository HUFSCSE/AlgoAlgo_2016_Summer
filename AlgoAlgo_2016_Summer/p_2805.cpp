#include<iostream>
#include<algorithm>
using namespace std;
long long arr[1000000];
int main() {
	int n, num;
	long long m = 0;
	cin >> n >> num;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		m = max(m, arr[i]);
	}
	long long left = 0;
	long long right = m;
	long long result = 0;
	while (left <= right) {
		long long t = 0;
		long long mid = (left + right) / 2;
		for (int i = 0; i < n; i++) {
			long long temp = arr[i] - mid;
			if (temp > 0)
				t += temp;
		}
		if (t >= num) {
			if (result < mid)
				result = mid;
			left = mid + 1;

		}
		else {
			right = mid - 1;
		}
	}
	cout << result << endl;
	return 0;
}