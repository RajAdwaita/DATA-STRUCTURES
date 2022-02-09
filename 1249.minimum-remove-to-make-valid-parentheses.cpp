/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    stack<int> s1;
    string minRemoveToMakeValid(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                s1.push(i);
            if (s[i] == ')')
            {
                if (s1.empty())
                    s[i] = '*';
                else
                    s1.pop();
            }
        }

        while (!s1.empty())
        {
            s[s1.top()] = '*';
            s1.pop();
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }

}

;
// @lc code=end
