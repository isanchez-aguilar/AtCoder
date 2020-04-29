/*
*	User: Isanchez_Aguilar
*	Problem: AtCoder ABC160E - Red and Green Apples
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int x, y, a, b , c;
	cin >> x >> y >> a >> b >> c;

	vector<Long> red(a), green(b), uncolored(c);

	for (Long& v : red)
		cin >> v;

	for (Long& v : green)
		cin >> v;

	for (Long& v : uncolored)
		cin >> v;

	sort(begin(red), end(red), greater<Long>());
	sort(begin(green), end(green), greater<Long>());

	for (int i  = 0; i < x; ++i)
		uncolored.emplace_back(red[i]);

	for (int i = 0; i < y; ++i)
		uncolored.emplace_back(green[i]);

	sort(begin(uncolored), end(uncolored), greater<Long>());

	
	uncolored.resize(x + y);

	cout << accumulate(begin(uncolored), end(uncolored), 0ll);

	return 0;
}
