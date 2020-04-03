/*
*	User: Isanchez_Aguilar
*	Problem: AtCoder ABC134B - Golden Apple
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	Long n, d;
	cin >> n >> d;

	cout << n / (d + d + 1ll) + (n % (d + d + 1ll) == 0?0:1ll);

	return 0;
}
