#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main() {
	int n;
	int num;
	vector<int> a1, a2;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		a1.push_back(num);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		a2.push_back(num);
	}
	sort(a1.begin(), a1.end());
	sort(a2.begin(), a2.end());
	int S = 0;
	for (int i = 0; i < n; i++)
	{
		S += a2[i] * a1[n - i - 1];
	}

	cout << S << endl;
	return 0;
}