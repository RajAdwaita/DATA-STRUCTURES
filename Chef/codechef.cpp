#include<bits/stdc++.h>
using namespace std;

int main()

{
	int n, am, bm, cm, tm, a, b, c;
	cin >> n;
	while (n--)
	{
		cin >> am >> bm >> cm >> tm >> a >> b >> c;
		if (a < am || b < bm || c < cm || (a + b + c) < tm)
		{
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
	return 0;

}