/*
*	User: Isanchez_Aguilar
*	Problem: AtCoder Educational DP - Vacation 
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector< vector<int> > activities(n, vector<int>(3));

	for (int i = 0; i < n; ++i)
		cin >> activities[i][0] >> activities[i][1] >> activities[i][2];

	int dp[n][3];

	for (int i = 0; i < 3; ++i)
		dp[0][i] = activities[0][i];

	for (int day = 1; day < n; ++day)
	{
		for (int i = 0; i < 3; ++i)
			dp[day][i] = INT_MIN;

		dp[day][0] = max(dp[day - 1][1], dp[day - 1][2]) + activities[day][0];
		dp[day][1] = max(dp[day - 1][0], dp[day - 1][2]) + activities[day][1];
		dp[day][2] = max(dp[day - 1][0], dp[day - 1][1]) + activities[day][2];

	}	


	cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});

	return 0;
}
