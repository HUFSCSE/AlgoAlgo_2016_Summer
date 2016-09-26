#include <stdio.h>
#include <string>
#include <math.h>
#include <iostream>
#include <functional>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <string.h>
#include <set>
using namespace std;
int main() {
	int num = 0, i;
	string name;
	cin >> name;
	for (i = 0; i<name.size(); i++) {
		if (name[i] == ',') {
			num++;
		}
	}
	printf("%d", num + 1);
	return 0;
}