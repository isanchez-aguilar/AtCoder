/*
*	User: Isanchez_Aguilar
*	Problem: AtCoder Educational DP - Sushi
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

double dp[320][320][320];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;

	vector<int> freq(4);

	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;

		++freq[v];
	}

	for (int k = 0; k <= 300; ++k)
	{
		for (int j = 0; j <= 300; ++j)
		{
			for (int i = 0; i <= 300; ++i)
			{
				if (i + j + k == 0)
					dp[i][j][k] = 0;
				else
				{
					dp[i][j][k] = double(n) / double(i + j + k);
					
					if (i > 0)
						dp[i][j][k] += double(i) * dp[i - 1][j][k] / double(i + j + k);
					if (j > 0)
						dp[i][j][k] += double(j) * dp[i + 1][j - 1][k] / double(i + j + k);
					if (k > 0)
						dp[i][j][k] += double(k) * dp[i][j + 1][k - 1] / double(i + j + k); 	
				}
			}
		}
	}

	cout << fixed << setprecision(9) << dp[freq[1]][freq[2]][freq[3]];

	return 0;
}
