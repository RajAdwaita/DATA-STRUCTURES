#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x, m, d, inp;
	cin >> inp;
	while (inp--)
	{
		cin >> x >> m >> d;
		int prod = x * m;
		int ub = x + d;
		if (prod <= ub)

		{
			cout << prod << endl;
		}

		else
		{
			cout << min(prod, ub) << endl;
		}
	}
}