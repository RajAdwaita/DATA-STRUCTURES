#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        int c0, c1;
        c0 = count(s.begin(), s.end(), '0');
        c1 = count(s.begin(), s.end(), '1');

        cout << c0 * a + c1 * b << endl;
    }
    return 0;
}