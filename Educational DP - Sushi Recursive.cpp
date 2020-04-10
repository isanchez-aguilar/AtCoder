/*
*	User: Isanchez_Aguilar
*	Problem: AtCoder Educational DP - Sushi
*/
#include <bits/stdc++.h>

using namespace std;
using Double = double;

int n;
vector<int> freq(4);
Double memo[301][301][301];
bool visited[301][301][301];

Double dp(int i, int j, int k)
{
	if (i + j + k == 0)
		return 0;

	Double& curr = memo[i][j][k];

	if (not visited[i][j][k])
	{
		visited[i][j][k] = true;
		curr = Double(n) / Double(i + j + k);

		if (i > 0)
			curr += Double(i) * dp(i - 1, j, k) / Double(i + j + k);

		if (j > 0)
			curr += Double(j) * dp(i + 1, j - 1, k) / Double(i + j + k);

		if (k > 0)
			curr += Double(k) * dp(i, j + 1, k - 1) / Double(i + j + k);
	}

	return curr;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		++freq[v];
	}

	memset(memo, 0, sizeof memo);
	memset(visited, false, sizeof visited);

	cout << fixed << setprecision(9) << dp(freq[1], freq[2], freq[3]);

	return 0;
}
