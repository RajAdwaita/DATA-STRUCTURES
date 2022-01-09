#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num = 4;
    vector<int> nn;
    int n = num;
    for (int i = 0; n > 0; i++)
    {
        nn.push_back(n % 2);
        n /= 2;
    }
    reverse(nn.begin(), nn.end());
    vector<int> bin;
    for (auto &i : nn)
    {
        // cout << i << endl;
        if (i == 1)
            bin.push_back(0);
        else
            bin.push_back(1);
    }
    int ter = 0;
    for (auto &i : bin)
    {
        ter = ter * 10 + i;
        // cout << i << endl;
    }
    int res = ter;
    int dec = 0;
    int i = 0;
    while (ter > 0)
    {
        int rem = ter % 10;
        ter /= 10;
        dec += rem * pow(2, i);
        ++i;
    }
    cout << dec << endl;

    return 0;
}