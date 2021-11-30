bool canVisitAllRooms(vector<vector<int>> &r)
{

    vector<int> vis(r.size(), false);
    bfs(r, 0, r.size() - 1, vis);
    for (int i = 0; i < r.size(); i++)
    {
        if (vis[i] == false)
            return false;
    }
    return true;
}
void bfs(vector<vector<int>> &r, int st, int end, vector<int> &vis)
{
    vis[st] = true;
    queue<int> q;
    q.push(st);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : r[u])
        {
            if (!vis[v] && u != v)
                bfs(r, v, end, vis);
        }
    }
}