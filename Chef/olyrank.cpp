#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> medals(6);
        for (int i = 0; i < 6; i++)
        {
            cin >> medals[i];
        }

        int first = medals[0] + medals[1] + medals[2];
        int second = medals[3] + medals[4] + medals[5];

        if (first > second)
        {
            cout << 1 << endl;
        }
        else
            cout << 2 << endl;
    }
    return 0;
}