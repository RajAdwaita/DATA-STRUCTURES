#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    int match[5];
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 5; i++)
        {
            cin >> match[i];
        }

        int ind = 0, eng = 0;

        for (int i = 0; i < 5; i++)
        {
            if (match[i] == 1)
            {
                ind += 1;
            }
            else if (match[i] == 2)
            {
                eng += 1;
            }
            else
            {
                ind += 1;
                eng += 1;
            }
        }
        if (ind > eng)
        {
            cout << "INDIA" << endl;
        }

        else if (eng > ind)
        {
            cout << "ENGLAND" << endl;
        }
        else
        {
            cout << "DRAW" << endl;
        }
    }
    return 0;
}