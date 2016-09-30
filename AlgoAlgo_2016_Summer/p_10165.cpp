#include <stdio.h>
#include <algorithm>
using namespace std;
struct intv {
	int s, e, i;
	bool operator <(const intv a) const { return s != a.s ? s < a.s : e > a.e; }
} I[500001];
int N, M; bool forb[500001];
int main(){
	scanf("%d %d", &N, &M);
	int over = 0;
	for (int i = 0; i<M; i++) {
		scanf("%d %d", &I[i].s, &I[i].e);
		I[i].i = i + 1;
		if (I[i].s > I[i].e) {
			over = max(over, I[i].e);
			I[i].e += N;
		}
	}
	sort(I, I + M);
	for (int i = 0; i<M; i++) 
		if (I[i].e <= over) forb[I[i].i] = 1;
		else over = I[i].e;
	for (int i = 1; i <= M; i++) if (!forb[i]) printf("%d ", i);
	return 0;
}