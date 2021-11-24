#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int posa = -1;
        // posa = s.find('a');
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'a')
            {
                posa = i;
                break;
            }
        }
        int count = 0;
        int flag = 0;
        // cout << posa;
        if (posa == -1)
        {
            cout << "NO" << endl;
        }
        else
        {
            int i = posa - 1;
            int j = posa + 1;
            char cc = 'b';

            while (i >= 0 || j < s.size())
            {
                if (s[i] == cc)
                {
                    i--;
                    cc++;
                    count++;
                }
                else if (s[j] == cc)
                {
                    j++;
                    cc++;
                    count++;
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
            if (flag != 1)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}