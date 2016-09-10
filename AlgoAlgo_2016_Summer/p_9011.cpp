#include<stdio.h>
#include<iostream>
#include<string.h>
#define MAX 101
using namespace std;

int n, m;
int input[MAX], output[MAX], used[MAX];

int main()
{
	scanf("%d", &n);

	while (n--)
	{
		bool ok = true;
		scanf("%d", &m);

		for (int i = 0; i < m; i++)
		{
			used[i] = i;
			scanf("%d", &input[i]);

		}

		for (int i = m - 1; i >= 0; i--)
		{
			for (int j = 0; j < m; j++)
			{
				if (used[j] == input[i])
				{
					output[i] = j + 1;
					used[j] = -1;

					for (int k = j + 1; k < m; k++)
					{
						if (used[k] != -1)
							used[k]--;
					}
					break;
				}
			}
		}

		for (int i = 0; i < m; i++)
		{
			if (used[i] != -1)
				ok = false;
		}

		if (!ok)
			cout << "IMPOSSIBLE\n";
		else
		{
			for (int i = 0; i < m; i++)
				printf("%d ", output[i]);
			cout << "\n";
		}

		memset(input, 0, sizeof(m));
		memset(output, 0, sizeof(m));

	}

	return 0;
}