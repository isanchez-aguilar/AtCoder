/*
*	User: Isanchez_Aguilar
*	Problem: AtCoder Educational DP - Grid 1 
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int h, w;
	cin >> h >> w;

	vector< vector<char> > grid(h, vector<char>(w));

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
			cin >> grid[i][j];
	}

	const Long MOD = 1000000007ll;

	vector< vector<Long> > dp(h, vector<Long>(w));

	dp[h - 1][w - 1] = 1;

	for (int j = w - 1; j >= 0; --j)
	{
		for (int i = h - 1; i >= 0; --i)
		{
			if (grid[i][j] == '.')
			{
				if (i + 1 < h)
					dp[i][j] = (dp[i][j] + dp[i + 1][j]) % MOD;
			
				if (j + 1 < w)
					dp[i][j] = (dp[i][j] + dp[i][j + 1]) % MOD;	
			}
		}
	}

	cout << dp[0][0];		

	return 0;
}
