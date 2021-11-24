#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        vector<int> nums;

        for (int i = 0; i < boxes.length(); i++)
        {
            int posCount = 0;
            char curr = boxes[i];
            for (int j = 0; j < boxes.length(); j++)
            {
                char move = boxes[j];

                if (i != j)
                {
                    if (curr == '1' && move == '1')
                    {
                        posCount += abs(i - j);
                    }
                }
            }
            nums.push_back(posCount);
        }
        return nums;
    }
};
// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }