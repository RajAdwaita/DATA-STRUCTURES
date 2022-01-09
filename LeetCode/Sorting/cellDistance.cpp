#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter)
    {
        vector<vector<int>> array;

        for (int i = 0; i < rows; i++)
        {

            for (int j = 0; j < cols; j++)
            {
                vector<int> temp;
                int t1 = abs(rCenter - i) + abs(cCenter - j);
                temp.push_back(t1);

                temp.push_back(i);
                temp.push_back(j);
                // sort(tem)
                array.push_back(temp);
            }
        }
        sort(array.begin(), array.end());
        vector<vector<int>> final;

        for (int i = 0; i < array.size(); i++)
        {
            vector<int> vv;
            vv.push_back(array[i][1]);
            vv.push_back(array[i][2]);
            final.push_back(vv);
        }
        return final;
    }
};

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }