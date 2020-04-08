/*
*	User: Isanchez_Aguilar
*	Problem: AtCoder Educational DP - Frog 1 
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int k, n;
	int heights[100001];

	cin >> n;
	
	k = 2;

	for (int i = 0; i < n; ++i)
		cin >> heights[i];

	int dp[100001];

	dp[0] = 0;
	for (int i = 1; i < n; ++i)
	{
		dp[i] = INT_MAX;

		for (int j = 1; i - j >= 0 and j <= k; ++j)
			dp[i] = min(dp[i], dp[i - j] + abs(heights[i] - heights[i - j]));
	}

	cout << dp[n - 1];

	return 0;
}
