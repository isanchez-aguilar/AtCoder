/*
*	User: Isanchez_Aguilar
*	Problem: AtCoder ABC134B - Golden Apple
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

const Long INF = 1e9+1;

Long dp[100][100001];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Long n, w;
	cin >> n >> w;

	vector< pair<Long, Long> > products(n);

	for (auto& p : products)
		cin >> p.first >> p.second;


	memset(dp, INF, sizeof dp);

	dp[0][0] = 0;

	dp[0][products[0].second] = products[0].first;

	for (int i = 1; i < n; ++i)
	{
		pair<Long, Long> p = products[i];
		
		for (int j = 0; j <= 100000; ++j)
		{
			dp[i][j] = dp[i - 1][j];

			if (j - p.second >= 0 and dp[i - 1][j - p.second] != INF)
				dp[i][j] = min(dp[i][j], dp[i - 1][j - p.second] + p.first);   
		}
	}

	Long ans = 0;

	for (int i = 100000; i >= 0; --i)
	{
		if (dp[n - 1][i] <= w)
		{
			ans = i;
			break;
		}
	}

	cout << ans;

	return 0;
}
