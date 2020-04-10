/*
*	User: Isanchez_Aguilar
*	Problem: AtCoder Educational DP - Coins
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<double> probability(n);

	for (double& p : probability)
		cin >> p;

	vector< vector<double> > dp(n + 1, vector<double>(n + 1, 0.0));

	dp[0][0] = 1.0;


	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			if (i - 1 >= 0)
				dp[i][j] += probability[i + j - 1] * dp[i - 1][j];
			if (j - 1 >= 0)
			{
				dp[i][j] += (1.0f - probability[i + j - 1]) * dp[i][j - 1];
			}
		}
	}

	double ans = 0;

	for (int i = 0; i <= n; ++i)
	{
		if (i >= n - i)
			break;

		ans += dp[n - i][i];
	}

	cout << fixed << setprecision(9) << ans;

	return 0;
}