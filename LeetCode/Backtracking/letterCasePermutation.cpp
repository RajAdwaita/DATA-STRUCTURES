// Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

// Return a list of all possible strings we could create. Return the output in any order.

// Example 1:

// Input: s = "a1b2"
// Output: ["a1b2","a1B2","A1b2","A1B2"]
// Example 2:

// Input: s = "3z4"
// Output: ["3z4","3Z4"]

// Constraints:

// 1 <= s.length <= 12
// s consists of lowercase English letters, uppercase English letters, and digits.

class Solution
{
public:
    void calc_disp(string s, vector<string> &ans, int l, int r)
    {
        if (l < r)
        {

            calc_disp(s, ans, l + 1, r);
            if (isalpha(s[l]))
            {
                s[l] = toupper(s[l]);
                calc_disp(s, ans, l + 1, r);
            }
        }
        else
        {
            ans.push_back(s);
        }
    }
    vector<string> letterCasePermutation(string s)
    {

        vector<string> ans;

        for (int i = 0; i < s.size(); i++)
        {
            s[i] = tolower(s[i]);
        }

        calc_disp(s, ans, 0, s.size());
        return ans;
    }
};