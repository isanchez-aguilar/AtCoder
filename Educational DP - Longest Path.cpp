/*
*	User: Isanchez_Aguilar
*	Problem: AtCoder Educational DP = Longest Path 
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> memo(100001, -1);
vector<int> graph[100001];

int dp(int u)
{
	if (memo[u] == -1)
	{
		memo[u] = 0;

		for (int v : graph[u])
			memo[u] = max(memo[u], 1 + dp(v));
	}

	return memo[u];
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].emplace_back(v);
	}

	int ans = 0;

	for (int i = 0; i < n; ++i)
		ans = max(ans, dp(i));

	cout << ans;

	return 0;
}
