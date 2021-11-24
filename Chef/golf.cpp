#include<bits/stdc++.h>
using namespace std;


int main()
{
	long int t;
	long int x, n, k;
	cin >> t;
	while (t--)
	{
		long int flag{0};
		cin >> n >> x >> k;

		if (x % k == 0)
		{
			cout << "YES" << endl;
			flag = 1;
		}
		if (flag == 0)
		{
			for (long int j = n + 1; j >= 0; j --)
			{
				if ((n + 1) - ((n + 1 - j)*k) == x)
				{
					cout << "YES" << endl;
					flag = 1;
					break;
				}

			}
		}
		if (flag == 0)
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}