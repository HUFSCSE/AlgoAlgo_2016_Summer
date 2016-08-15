#include<iostream>
#include<algorithm>
using namespace std;

unsigned long long arr[10000];
int main() {
	int k, num;
	cin >> k >> num;
	for (int i = 0; i < k; i++)
		cin >> arr[i];
	sort(arr, arr + k);
	unsigned long long left = 1;
	unsigned long long right = arr[k - 1];
	unsigned long long result = left;
	while (left <= right) {
		unsigned long long mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < k; i++) 
			cnt += arr[i] / mid;
		if (cnt >= num) {
			if (result < mid)
				result = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << result << endl;
	return 0;
}