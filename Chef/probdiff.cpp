#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        map<int, int> ques;
        int n;

        for (int i = 0; i < 4; i++)
        {
            cin >> n;
            ques[n]++;
        }

        if (ques.size() <= 1)
            cout << 0 << endl;

        else if (ques.size() == 4 || ques.size() == 3)
            cout << 2 << endl;

        else
        {
            auto it = ques.begin();
            int a = it->second;
            it++;
            int b = it->second;
            if (a == b)
                cout << 2 << endl;
            else
                cout << 1 << endl;
        }
    }

    return 0;
}