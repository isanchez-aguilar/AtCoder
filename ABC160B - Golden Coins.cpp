/*
*	User: Isanchez_Aguilar
*	Problem: AtCoder ABC160B - Golden Coins
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Long n;
	cin >> n;

	cout << (n / 500ll) * 1000ll + ((n % 500ll) / 5ll) * 5ll;

	return 0;
}
