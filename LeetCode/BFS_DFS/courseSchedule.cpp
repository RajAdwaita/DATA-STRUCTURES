// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ ai, bi ] indicates that you must take course bi first if you want to take course ai.

//                                                                                                                                                           For example,
//                                                                                                                                        the pair[0, 1], indicates that to take course 0 you have to first take course 1. Return the ordering of courses you should take to finish all courses.If there are many valid answers, return any of them.If it is impossible to finish all courses, return an empty array.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> res;
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto &p : prerequisites)
        {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            res.push_back(cur);
            for (auto &p : graph[cur])
            {
                indegree[p]--;
                if (indegree[p] == 0)
                    q.push(p);
            }
        }
        if (res.size() == numCourses)
            return res;
        else
            return {};
    }
};

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }