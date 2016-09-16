#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
using namespace std;

#define MOD 1000000003
int n, k;
int bi[2][1010][1010];
int min(int a, int b) { if (a > b)return b; else return a; }
int solve(int a, int b,bool c) {
	if (b == k) return 1;
	if (a >= n - c) return 0;
	if (bi[c][a][b] == -1)
		bi[c][a][b] = ( solve(a+2,b+1,c) + solve(a+1,b,c) )%MOD;
	return bi[c][a][b];
}

int main() {
	memset(bi,-1, sizeof(bi));
	scanf("%d %d", &n, &k);
	cout << (solve(1, 0, 0) + solve(2, 1, 1)) % MOD << endl;
	return 0;
}