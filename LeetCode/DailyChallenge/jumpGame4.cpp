// Given an array of integers arr, you are initially positioned at the first index of the array.

// In one step you can jump from index i to index:

// i + 1 where: i + 1 < arr.length.
// i - 1 where: i - 1 >= 0.
// j where: arr[i] == arr[j] and i != j.
// Return the minimum number of steps to reach the last index of the array.

// Notice that you can not jump outside of the array at any time.

// Example 1:

// Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
// Output: 3
// Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
// Example 2:

// Input: arr = [7]
// Output: 0
// Explanation: Start index is the last index. You do not need to jump.
// Example 3:

// Input: arr = [7,6,9,6,9,6,9,7]
// Output: 1
// Explanation: You can jump directly from index 0 to index 7 which is last index of the array.

// Constraints:

// 1 <= arr.length <= 5 * 104
// -108 <= arr[i] <= 108

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        unordered_map<int, vector<int>> mp;
        int m = arr.size();
        if (m == 1)
            return 0;
        int c = 0;
        for (int i = 0; i < m; i++)
        {
            // for (int j = 0; j < n; j++)
            // {
            mp[arr[i]].push_back(i);
            // }
        }

        queue<int> q;
        q.push(0);

        while (!q.empty())
        {
            c++;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int p = q.front();
                q.pop();

                if (p + 1 < m && mp.find(arr[p + 1]) != mp.end())
                {
                    q.push(p + 1);
                }

                if (p - 1 >= 0 && mp.find(arr[p - 1]) != mp.end())
                {
                    q.push(p - 1);
                }

                if (mp.find(arr[p]) != mp.end())
                {
                    for (auto i : mp[arr[p]])
                    {
                        if (i != p)
                            if (i == m - 1)
                                return c;
                        q.push(i);
                    }
                }

                mp.erase(arr[p]);
            }
        }
        return c;
    }
};