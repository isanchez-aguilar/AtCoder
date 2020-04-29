/*
*	User: Isanchez_Aguilar
*	Problem: AtCoder ABC160C - Traveling Salesman around Lake
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Long n;
	int k;

	cin >> n >> k;

	vector<Long> vals(k);

	for (int i = 0; i < k; ++i)
		cin >> vals[i];

	Long ans = vals.back() - vals[0];

	for (int i = 0; i < k; ++i)
	{
		Long currAns = vals[i] + n - vals.back() + (vals.back() - vals[i]);

		ans = min(ans, currAns);

		if (i > 0)
		{
			currAns = n - vals[i] + vals[i - 1];

			ans = min(ans, currAns);
		}
	}

	cout << ans;

	return 0;
}
