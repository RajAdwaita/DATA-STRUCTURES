#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 8;
    int bin = 0;
    // while (n > 0)
    // {
    //     int d = n % 2;
    //     bin = bin * 10 + d;
    //     n = n / 2;
    // }
    // cout << bin << endl;
    string s = "88";
    cout << stoi(s) + 45 << endl;

    return 0;
}

class Solution
{
public:
    int toBin(string s)
    {
        int n = stoi(s);
        int bin = 0;
        int rem, i = 1;

        while (n != 0)
        {
            rem = n % 2;
            n /= 2;
            bin += rem * i;
            i *= 10;
        }

        return bin;
    }

    int toDec(string s)
    {
        int n = stoi(s);
        int dec = 0;
        int rem, i = 1;

        while (n != 0)
        {
            rem = n % 10;
            n /= 10;
            dec += rem * i;
            i *= 2;
        }

        return dec;
    }
    string addBinary(string a, string b)
    {
        int a = toBin(a);
        int b = toBin(b);
        int c = a + b;
        int d = toDec(c);
        return to_string(d);
    }
};