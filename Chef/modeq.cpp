#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long t;
	cin >> t;
	while (t--)
	{
		long long m, n;
		cin >> n >> m;
		long long count = 0;
		std::vector<long long> mod(n + 1, 1);
		for (int i = 2; i <= n; i++)
		{
			long long x = m % i;
			count += mod[x];

			for (int j = x; j <= n; j += i)
			{
				mod[j]++;
			}
		} cout << count << endl;
	}
	return 0;

}