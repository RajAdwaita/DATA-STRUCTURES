#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> rooms(10);
    for (int i = 0; i < str.length(); i++)
    {
        int rcount = 9, lcount = 0;
        int flag = 0;
        int num = 0;
        char c = str[i];
        if (isdigit(c))
        {
            num = c - 48;
            // cout << num << endl;
            rooms[num] = 0;
        }
        if (c == 'L')
        {
            while (rooms[lcount])
                lcount++;

            rooms[lcount] = 1;
        }
        else if (c == 'R')
        {
            while (rooms[rcount])
                rcount--;
            rooms[rcount] = 1;
        }
    }
    for (auto i : rooms)
        // {
        cout << i;
    // }

    return 0;
}