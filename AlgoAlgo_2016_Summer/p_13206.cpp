#include <iostream>
#include <vector>
#define lli long long int
using namespace std;

vector<lli> T;
long long arr[1001];
lli gcd(lli a, lli b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

lli gcd_vector( lli b) {
	lli ma = 1;
	for (int i = 0; i<T.size(); i++)
		ma = ma*T[i] % b;
	return gcd(b, ma);
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		int c;
		cin >> c;
		for (int i = 0; i < c; i++) {
			int temp;
			cin >> temp;
			arr[temp] = true;
		}
		lli answer = 1;
		for (int i = 1; i <= 1000; i++) {
			if (arr[i]) {
				lli factor = i / gcd_vector(i);
				T.push_back(factor);
				answer = (answer*factor) % 1000000007;
			}
		}
		cout << answer << "\n";

		for (int i = 0; i < 1001; i++)
			arr[i] = false;
		T.clear();
	}
}