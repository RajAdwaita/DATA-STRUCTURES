// Anti - theft security devices are activated inside a bank.You are given a 0 - indexed binary string array bank representing the floor plan of the bank, which is an m x n 2D matrix.bank[i] represents the ith row, consisting of '0' s and '1' s.'0' means the cell is empty, while '1' means the cell has a security device.

//                                                                                                                                                                                                                                                                                There is one laser beam between any two security devices if both conditions are met :

//     The two devices are located on two different rows : r1 and r2,
//     where r1 < r2.For each row i where r1 < i < r2, there are no security devices in the ith row.Laser beams are independent, i.e., one beam does not interfere nor join with another.

//                                                                                                                                     Return the total number of laser beams in the bank.

#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int n = bank.size();
        int m = bank[0].size();
        int ans = 0;
        char ch = '1';
        vector<int> vv;
        for (int i = 0; i < n; i++)
        {
            int countOne = 0;
            int c1 = count(bank[i].begin(), bank[i].end(), ch);
            if (c1 != 0)
                vv.push_back(c1);
        }
        int tot = 0;
        if (vv.size() == 1)
        {
            return 0;
        }
        for (int i = 0; i < vv.size() - 1; i++)
        {
            tot += vv[i] * vv[i + 1];
        }
        return tot;
    }
};