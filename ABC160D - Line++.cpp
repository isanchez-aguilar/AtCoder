/*
*	User: Isanchez_Aguilar
*	Problem: AtCoder ABC160D - Line++
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x, y;
	cin >> n >> x >> y;

	if (x > y)
		swap(x, y);

	vector<int> ans(n);

	if (x + 1 != y)
	{
		int d = y - x;

		for (int i = 1; i <= n; ++i)
		{
			for (int j = i + 1; j <= n; ++j)
			{
				int currD = j - i;

				if (j >= y and i <= x)
					currD -= (d - 1);
				else if (i <= x and x < j and j < y)
					currD = min(currD, abs(y - j) + 1 + x - i);				
				else if (x < i and i < y)
					currD = min(currD, abs(j - y) + abs(x - i) + 1);

				++ans[currD];
			}
		}
	}

	for (int i = 1; i < n; ++i)
		cout << ans[i] << "\n";

	return 0;
}
