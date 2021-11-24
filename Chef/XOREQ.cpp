#include<bits/stdc++.h>
using namespace std;



int main()
{
	long long p = pow(10, 9) + 7;

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		long long x = 2;
		long long temp = 1;
		long long y = n - 1;

		while (y)
		{
			if (y % 2 == 1)
			{
				temp = temp * x;
			}

			x = x * x;
			y = y / 2;
		}
		cout << temp % p << endl;
	}
}