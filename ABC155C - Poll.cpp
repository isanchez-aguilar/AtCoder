/*
*	User: Isanchez_Aguilar
*	Problem: AtCoder ABC155C - Poll 
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int maxFreq = 0;
	map<string, int> freq;

	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;

		++freq[s];

		if (freq[s] > maxFreq)
			maxFreq = freq[s];
	}


	for (auto p : freq)
	{
		if (p.second == maxFreq)
			cout << p.first << "\n";
	}

	return 0;
}
