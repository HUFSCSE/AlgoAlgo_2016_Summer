#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int N;

int main()
{
	cin >> N;
	vector < pair<int, int> > station(N);
	for (int i = 0; i < N; i++)
		cin >> station[i].first >> station[i].second;
	sort(station.begin(), station.end());

	int L, P;
	cin >> L >> P;

	priority_queue< int > PQ;
	int idx = 0;
	bool fail = false;
	int cnt = 0;
	while (P < L) {
		for (idx; idx < N; idx++) {
			if (station[idx].first <= P)
				PQ.push(station[idx].second);
			else
				break;
		}
		if (!PQ.empty()) {
			P += PQ.top();
			PQ.pop();
			cnt++;
		}
		else {
			fail = true;
			break;
		}
	}
	if (fail)
		cout << -1 << endl;
	else
		cout << cnt << endl;

	return 0;
}