/*
*	User: Isanchez_Aguilar
*	Problem: AtCoder ABC156A - Poor 
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

	set<int> vals;

	for (int i = 0; i < 3; ++i)
	{
		int val;
		cin >> val;
		
		vals.insert(val);
	}

	if (vals.size() == 2)
		cout << "Yes\n";
	else
		cout << "No\n";


	return 0;
}
