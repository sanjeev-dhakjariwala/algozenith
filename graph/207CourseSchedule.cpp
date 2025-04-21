#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/course-schedule/description

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int m = prerequisites.size();
        vector<vector<int>> graph(numCourses);
        vector<int> in_degree(numCourses, 0);
        for (auto pre : prerequisites)
        {
            int u = pre[0];
            int v = pre[1];
            graph[v].push_back(u);
            in_degree[u]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (in_degree[i] == 0)
            {
                q.push(i);
            }
        }
        // for(int i = 0; i < numCourses; i++){
        //     cout << in_degree[i] << " ";
        // }
        // cout << "\n";
        int visitedCourse = 0;
        while (q.empty())
        {
            auto t = q.front();
            q.pop();
            visitedCourse++;
            for (auto neigh : graph[t])
            {
                in_degree[neigh]--;
                if (in_degree[neigh] == 0)
                {
                    q.push(neigh);
                }
            }
        }
        // for(int i = 0; i < numCourses; i++){
        //     if(in_degree[i] != 0){
        //     return false;
        //     }
        // }
        // cout << "\n";
        return visitedCourse == numCourses;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    cout << s.canFinish(2, prerequisites) << endl; // false
    prerequisites = {{1, 0}};
    cout << s.canFinish(2, prerequisites) << endl; // true
    return 0;
}