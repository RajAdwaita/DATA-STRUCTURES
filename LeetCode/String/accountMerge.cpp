#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(vector<string> &res, string &s, int i, int j)
    {
        if (i == s.size() && j == s.size())
        {
            res.push_back(s);
            return;
        }
        if (i < s.size())
        {
            s[i] = s[j];
            dfs(res, s, i + 1, j + 1);
            s[i] = s[j];
        }
        if (j < s.size())
        {
            s[i] = s[j];
            dfs(res, s, i, j + 1);
            s[i] = s[j];
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        unordered_map<string, string> emailToName;
        unordered_map<string, vector<string>> graph;
        for (auto &account : accounts)
        {
            string name = account[0];
            for (int i = 1; i < account.size(); i++)
            {
                string email = account[i];
                emailToName[email] = name;
                graph[email].push_back(email);
                for (int j = i + 1; j < account.size(); j++)
                {
                    string email2 = account[j];
                    graph[email].push_back(email2);
                    graph[email2].push_back(email);
                }
            }
        }
        unordered_map<string, bool> visited;
        vector<vector<string>> ans;
        for (auto &email : graph)
        {
            if (visited[email.first])
                continue;
            visited[email.first] = true;
            vector<string> component;
            dfs(email.first, email, visited, component, graph);
            sort(component.begin(), component.end());
            component.insert(component.begin(), emailToName[email.first]);
            ans.push_back(component);
        }
        return ans;
    }
};
