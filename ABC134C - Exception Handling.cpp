/*
*	User: Isanchez_Aguilar
*	Problem: AtCoder ABC134C - Exception Handling
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	int n;

	cin >> n;

	Long a[n];
	multiset<int> vals;

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		vals.insert(a[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		auto it = vals.find(a[i]);
		vals.erase(it);

		cout << *(--end(vals)) << "\n";

		vals.insert(a[i]);
	}

	return 0;
}
