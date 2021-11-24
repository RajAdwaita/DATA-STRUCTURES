#include <bits/stdc++.h>
using namespace std;

double calc_avg(vector<int> v1)
{
    double sum = 0.0;
    for (auto i : v1)
    {
        sum += i;
    }
    sum = sum / v1.size();

    return sum;
}

int main()
{
    int t;
    cin >> t;
    while (t--)

    {
        vector<int> a;
        vector<int> b;
        int n;
        cin >> n;
        vector<int> nums(n);

        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++)
        {
            b.push_back(nums[i]);
        }

        double tot = calc_avg(b) + nums[nums.size() - 1];
        cout << tot << endl;
    }

    return 0;
}