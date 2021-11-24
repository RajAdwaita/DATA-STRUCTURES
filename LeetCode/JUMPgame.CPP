#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);

    int arr[5] = {1, 3, 2, 0, 2};
    // int arr[5] = {1, 2, 1, 0, 2};
    int n = 0;
    int neww = 0;
    int x = arr[0];
    if (x == 0)
    {
        cout << "FALSE" << endl;
        exit(0);
    }
    int n1 = 0;

    while (n1 < 5 - 1)
    {
        n += x;
        neww = arr[n];
        if (neww == 0)
        {
            cout << "FALSE" << endl;
            break;
        }
        x = neww;
        n1 += x;
    }

    if (n1 > 4)
    {
        cout << "TRUE" << endl;
    }

    return 0;
}