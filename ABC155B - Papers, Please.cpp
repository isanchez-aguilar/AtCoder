/*
*	User: Isanchez_Aguilar
*	Problem: AtCoder ABC155B - Papers, Please 
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
 
using namespace std;
using Long = long long;
 
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	bool isGood = true;
 
	for (int i = 0; i < 3; ++i)
	{
		int val;
		cin >> val;
			
		if (val % 2 == 0)	
			isGood &= (val % 3 == 0 or val % 5 == 0);
	}
 
 
	if (isGood)
		cout << "APPROVED\n";
	else
		cout << "DENIED\n";
 
	return 0;
}