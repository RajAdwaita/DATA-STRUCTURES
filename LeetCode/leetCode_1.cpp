#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int c5 = 0;
        int c10 = 0;
        for (int i = 0; i < bills.size(); i++)
        {
            int cash = bills[i];
            if (cash == 5)
            {
                c5++;
            }
            else if (cash == 10)
            {
                if (c5 < 1)
                    return false;
                else
                {
                    c5--;
                    c10++;
                }
            }
            else if (cash == 20)
            {
                if (c5 == 0 && c10 == 0)
                {
                    return false;
                }
                else if (c10 < 1)
                {
                    if (c5 < 3)
                    {
                        return false;
                    }
                    else
                    {
                        c5 -= 3;
                    }
                }
                else if (c5 == 0 && c10 > 0)
                {
                    return false;
                }
                else if (c5 > 0 && c10 > 0)
                {
                    c5--;
                    c10--;
                }
            }
        }
        return true;
    }
};