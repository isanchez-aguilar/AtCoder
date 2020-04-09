/*
*	User: Isanchez_Aguilar
*	Problem: AtCoder Educational DP - LCS
*/
#include <bits/stdc++.h>

using namespace std;

int dp[3002][3002];
short prevDp[3002][3002];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s, t;
	cin >> s >> t;


	memset(dp, -3001, sizeof dp);
	memset(prevDp, -1, sizeof prevDp);
	
	for (int i = 0; i <= t.size(); ++i)
	{
		dp[0][i] = 0;
		prevDp[0][i] = -1;
	}

	for (int i = 0; i <= s.size(); ++i)
	{
		dp[i][0] = 0;
		prevDp[i][0] = -1;
	}

	for (int i = 1; i <= s.size(); ++i)
	{
		for (int j = 1; j <= t.size(); ++j)
		{
			if (s[i - 1] == t[j - 1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
				prevDp[i][j] = 0;
			}
			else
			{
				if (dp[i - 1][j] < dp[i][j - 1])
				{
					dp[i][j] = dp[i][j - 1];
					prevDp[i][j] = 1;
				}
				else
				{
					dp[i][j] = dp[i - 1][j];
					prevDp[i][j] = 2;
				}
			}
		}
	}

	int i = s.size();
	int j = t.size();
	string ans = "";

	while (i > 0 && j > 0)
	{
		if (prevDp[i][j] == 0)
			ans += s[i - 1], --i, --j;
		else if (prevDp[i][j] == 1)
			--j;
		else
			--i;
	}

	reverse(begin(ans), end(ans));

	cout << ans;

	return 0;
}
