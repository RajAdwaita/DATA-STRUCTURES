class Solution
{
public:
    set<int> s;
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        vector<vector<int>> res;

        for (int i = 0; i < groupSizes.size(); i++)
        {
            // if(s.find(groupSizes[i])==s.end())
            s.insert(groupSizes[i]);
        }
        map<int, vector<int>> m;

        vector<int> temp;
        for (auto &j : s)
        {
            for (int i = 0; i < groupSizes.size(); i++)
            {
                if (groupSizes[i] == j)
                {
                    m[j].push_back(i);
                }
            }
        }

        for (auto &i : m)
        {
            if (i.second.size() == 1)
            {
                res.push_back(i.second);
            }
            else
            {
                for (int j = 0; j < i.second.size(); j++)
                {
                    temp.push_back(i.second[j]);
                    if (temp.size() == i.first)
                    {
                        res.push_back(temp);
                        temp.clear();
                    }
                }
            }
        }
        return res;
    }
};