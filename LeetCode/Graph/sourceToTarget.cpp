// Given a directed acyclic graph(DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

//                                                                             The graph is given as follows : graph[i] is a list of all nodes you can visit from node i(i.e., there is a directed edge from node i to node graph[i][j])
//                                                                                                                 .

class Solution
{
public:
    void dfs(vector<vector<int>> &graph, int n, int s, int d, vector<int> &visited, vector<int> &path)
    {
        // visited[cur] = 1;
        // path.push_back(cur);
        if (s == d)
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < graph[cur].size(); i++)
        {
            if (visited[graph[cur][i]] == 0)
                dfs(graph, n, graph[cur][i], d, visited, path);
        }
        path.pop_back();
        // visited[cur] = 0;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> res;
        vector<int> path;
        int d = graph.size();
        path.push_back(0);
        dfs(graph, n, 0, d, path, res, path);
        return res;
    }
};