// #include <bits/stdc++.h>
// using namespace std;

// typedef long long int ll;
// int gcd(int a, int b)
// {
//     if (a == 0)
//         return b;
//     return gcd(b % a, a);
// }
// int findGCD(int arr[], int n)
// {
//     int result = arr[0];
//     for (int i = 1; i < n; i++)
//     {
//         result = gcd(arr[i], result);

//         if (result == 1)
//         {
//             return 1;
//         }
//     }
//     return result;
// }
// int main()
// {
//     ll t, i, j;
//     cin >> t;
//     while (t--)
//     {
//         ll nn;
//         cin >> nn;
//         int nums[nn];
//         int max = 0;
//         int pos = 0;
//         ll ss{0};
//         for (i = 0; i < nn; i++)
//         {
//             cin >> nums[i];
//             ss += nums[i];
//             if (nums[i] > max)
//             {
//                 max = nums[i];
//                 pos = i;
//             }
//         }
//         int n = sizeof(nums) / sizeof(nums[0]);
//         ll h = findGCD(nums, n);

//         nums[pos] = h;
//         ss = ss - max + h;
//         cout << ss / h << endl;
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int findGCD(int arr[], int n)
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);

        if (result == 1)
        {
            return 1;
        }
    }
    return result;
}
int main()
{
    ll t, i, j;
    cin >> t;
    while (t--)
    {
        ll n, num{0};

        cin >> n;
        vector<ll> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        ll max = *max_element(a.begin(), a.end());
        ll min = *min_element(a.begin(), a.end());

        for (i = 0; i < n; i++)
        {
            if (a[i] == max)
            {
                a[i] = min;
                break;
            }
        }

        for (i = 0; i < n; i++)
        {
            num = num + (a[i] / min);
        }

        cout << num << endl;
    }

    return 0;
}