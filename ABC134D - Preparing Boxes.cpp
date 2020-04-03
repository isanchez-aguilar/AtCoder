/*
*	User: Isanchez_Aguilar
*	Problem: AtCoder ABC134D - Preparing Boxes
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	int n;
	cin >> n;

	vector<int> a(n);

	for (int& v : a)
		cin >> v;

	bool can = true;
	vector<int> boxes(n);

	for (int i = n - 1; i >= 0; --i)
	{
		int currBalls = 0;
		
		for (int j = 2 * (i + 1) - 1; j < n; j += (i + 1))
			currBalls += boxes[j];

		if (a[i] == (currBalls + 1) % 2)
		{
			boxes[i] = 1;
		}
	}

	cout << count(begin(boxes), end(boxes), 1) << "\n";


	for (int i = 0; i < n; ++i)
	{
		if (boxes[i] == 1)
			cout << i + 1 << " ";
	}

	return 0;
}
