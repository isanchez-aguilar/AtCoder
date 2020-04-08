/*
*	User: Isanchez_Aguilar
*	Problem: AtCoder Educational DP - Knapsack 1 
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, w;
	cin >> n >> w;

	vector< pair<Long, Long> > product(n);

	for (auto& p : product)
		cin >> p.first >> p.second;

	Long dp[n][w + 1];

	memset(dp, 1e9, sizeof dp);

	dp[0][0] = 0;
	
	for (int i = product[0].first; i <= w; ++i)	
		dp[0][i] = product[0].second;

	for (int i = 1; i < n; ++i)
	{
		pair<Long, Long> p = product[i];

		for (int j = 0; j < p.first and j <= w; ++j)
			dp[i][j] = dp[i - 1][j]; 

		for (int j = p.first; j <= w; ++j)
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - p.first] + p.second);
	}	
	

	cout << dp[n - 1][w];


	return 0;
}
