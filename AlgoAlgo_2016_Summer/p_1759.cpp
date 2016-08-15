#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> input;
vector<int> aeiou;
vector<bool> ac;
vector<bool> ec;
vector<int> etc;
int main() {
	int size, m;
	cin >> size >> m;
	for (int i = 0; i < m; i++) {
		char t;
		cin >> t;
		input.push_back(t-'a');
		if (t == 'a' || t == 'e' || t == 'i' ||
			t == 'o' || t == 'u')
			aeiou.push_back(t - 'a');
		else
			etc.push_back(t - 'a');
	}	
	for (int i = 0; i < aeiou.size(); i++) {
		vector<int> p;
		p.push_back(i);
		ac[i] = true;
		char a = aeiou[i];
		for (int j = 0; j < etc.size() - 1; j++) {
			p.push_back(j);
			ec[j] = true;
			char b = etc[j];
			for (int k = 1; k < etc.size(); k++) {
				ec[k] = true;
				char c = etc[k];
				p.push_back(k);
				for (int z = 0; z < aeiou.size(); i++)
					if (ac[aeiou[z]] == false)
						p.push_back(aeiou[z]);
				for (int z = 0; z < etc.size(); i++)
					if (ec[etc[z]] == false)
						p.push_back(etc[z]);



			}
		}
	}




	return 0;
}