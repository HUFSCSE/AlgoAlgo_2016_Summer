#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#define MAX 1001
using namespace std;

int t, n;
int era[MAX], res[3];
bool del[MAX], ok = false;

bool sol(int num, int remain)
{
	if (!remain)
		return ok = true;
	if (!num || num == 1)
		return false;
	for (int i = num; i >= 2; i--)
	{
		if (era[i] && !ok)
		{
			res[3 - remain] = i;
			if (!sol(num - i, remain - 1))
				res[3 - remain] = 0;
		}
	}
	if (ok)
		return ok;
	else
		return false;
}

int main(){
	for (int i = 2; i < MAX; i++)
	{
		if (!del[i])
			era[i] = 1;
		for (int j = i*i; j < MAX; j += i)
			del[j] = true;
	}
	cin >> t;
	while (t--){
		cin >> n;

		sol(n, 3);
		sort(res, res + 3);
		if (ok)
		{
			for (int i = 0; i < 3; i++)
				printf("%d ", res[i]);
		}
		else
			printf("0");
		cout << endl;
		memset(res, 0, sizeof(n));
		ok = false;
	}
	return 0;
}