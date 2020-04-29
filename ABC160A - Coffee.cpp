/*
*	User: Isanchez_Aguilar
*	Problem: AtCoder ABC160A - Coffee
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	string ans = (s[2] == s[3] and s[4] == s[5]?"Yes":"No");

	cout << ans;

	return 0;
}
