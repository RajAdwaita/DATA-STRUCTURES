#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    int a, b, c, d;
    cin >> t;
    while (t--)
    {
        int m_bags = 0;
        int l_bags = 0;
        cin >> a >> b >> c >> d;
        if (a <= b && b <= c && c <= d)
        {
            int ss = a + b + c;
            // m_bags = ss / d;
            // l_bags = ss % d;
            // cout << m_bags << " " << l_bags << endl;
            // if (l_bags > 0)
            // {
            //     cout << m_bags + 1 << endl;
            // }
            // else
            //     cout << m_bags << endl;
            int bags = 0;
            if (ss <= d)
            {
                // cout << 1 << endl;
                bags += 1;
            }

            else
            {
                if (a + b <= d || a + c <= d || b + c <= d)

                {
                    bags += 2;
                }
                else
                {
                    bags += 3;
                }
            }
            cout << bags << endl;
        }
        else
            continue;
    }

    return 0;
}