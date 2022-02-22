
class Solution
{
public:
    void dfs(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &temp, int i)
    {
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }

        while (i < candidates.size() && target >= candidates[i])
        {
            temp.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], ans, temp, i);
            ++i;
            temp.pop_back();
            // i++;
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        int i = 0;
        dfs(candidates, target, ans, temp, i);

        return ans;
    }
};
