#include <bits/stdc++.h>
using namespace std;
int fact(int x)
{
    if (x == 1)
        return 1;
    else

        return x * fact(x - 1);
}

int zeroCount(int x)
{
    int flag = -1;
    int c = 0;
    while (flag != 0 && x > 0)
    {
        if (x % 10 == 0)
            c++;
        else
            flag = 0;
        x /= 10;
    }
    return c;
}
int trailingZeroes(int n)
{

    // cout<<fact(n)<<endl;

    // return fact(n);
    int f = fact(n);
    return zeroCount(f);
}

int main()
{
    std::ios::sync_with_stdio(false);

    cout << trailingZeroes(5);

    return 0;
}