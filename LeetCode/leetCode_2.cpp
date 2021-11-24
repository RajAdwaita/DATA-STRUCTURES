#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        if (flowerbed.size() == 1)
        {
            if (flowerbed[0] == 0 && n <= 1 || flowerbed[0] == 1 && n == 0)
            {
                return true;
            }
            return false;
        }
        for (int i = 0; i < flowerbed.size(); i++)
        {
            int curr = flowerbed[i];
            if (n == 0)
                return true;

            if (i == 0 || i == flowerbed.size() - 1)
            {
                if (i == 0)
                {
                    if (flowerbed[i] == 0 && flowerbed[i + 1] == 0)
                    {
                        flowerbed[i] = 1;
                        n--;
                        if (n == 0)
                            return true;
                    }
                }
                else if (i == flowerbed.size() - 1)
                {
                    if (flowerbed[i] == 0 && flowerbed[i - 1] == 0)
                    {
                        flowerbed[i] = 1;
                        n--;
                        if (n == 0)
                            return true;
                    }
                }
            }

            if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                n--;
                if (n == 0)
                    return true;
            }
        }
        if (n != 0)
            return false;
        else
        {
            return true;
        }
    }
};