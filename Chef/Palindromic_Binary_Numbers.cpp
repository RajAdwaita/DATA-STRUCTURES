// We call a non - negative number x good if its binary representation is palindromic.For example, 107 is good because its binary representation is 1101011 which is palindromic while 10 is not good because its binary representation is 1010 which is not palindromic.

//                                                                                                 Recall that,
//     a string is said to be palindromic if it reads the same backward as forward.

//     You are given a number n.You have to express n as a sum of at most 12 good numbers.If there exist multiple answers,
//     print any one of them.

#include <bits/stdc++.h>
using namespace std;

int decimal_to_binary(int x)
{
    int ans = 0;
    int i = 0;
    while (x > 0)
    {
        ans += (x % 2) * pow(10, i);
        x /= 2;
        i++;
    }
    return ans;
}
bool isPalindrome(int x)
{
    int temp = x;
    int rev = 0;
    while (x > 0)
    {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return temp == rev;
}
int sum(vector<int> v1)
{
    int ans = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        ans += v1[i];
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        int cc = 0;
        int ss = 0;
        int i = 1;
        vector<int> v;
        while (ss < n)
        {
            int x = decimal_to_binary(i);
            if (isPalindrome(x))
            {
                v.push_back(i);
                // ans += i;
                // cc++;
                ss += i;
                cc++;
            }

            i++;
        }

        cout << cc << endl;
        for (auto &i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}