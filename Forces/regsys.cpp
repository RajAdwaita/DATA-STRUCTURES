#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    map<string, int> m;
    while (t--)
    {
        string st;
        cin >> st;
        if (m[st] == 0)
        {
            cout << "OK" << endl;
            m[st] += 1;
        }
        else
        {
            auto it = m.find(st);
            cout <<

                st << "" << it->second << endl;
            m[st] += 1;
        }
    }
    return 0;
}