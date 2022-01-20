#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> v = {1, 4, 2, 3};
    vector<int> v1;
    for (auto &i : v)
    {
        v1.push_back(i);
    }
    sort(v1.begin(), v1.end());
    if (v == v1)
        cout << "T";
    else
    {
        cout << "F";
    }

    return 0;
}