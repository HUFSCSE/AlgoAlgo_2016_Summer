#include<cstdio>
#include<iostream>
using namespace std;

int arr[10001];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		arr[a] += 1;
	}
	for (int i = 1; i <= 10000; i++) {
		for (int j = arr[i]; j > 0; j--) {
			printf("%d\n", i);
		}
	}
	return 0;
}