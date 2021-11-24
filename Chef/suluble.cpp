#include<bits/stdc++.h>
using namespace std;


int main()
{
	int t;
	int x, a, b;
	cin >> t;
	while (t--)
	{
		cin >> x >> a >> b;
		int tot{0};
		tot = a + (100 - x) * b;
		tot *= 10;
		cout << tot << endl;
	}
	return 0;
}