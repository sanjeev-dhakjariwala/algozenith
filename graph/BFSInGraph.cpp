#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> vis;
vector<int> ans;
void bfs(int node)
{
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        auto t = q.front();
        vis[t] = 1;
        ans.push_back(t);
        q.pop();
        for (auto neigh : graph[t])
        {
            if (!vis[neigh])
            {
                q.push(neigh);
            }
        }
    }
}
vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    // Write your code here.
    int m = adj.size();
    graph.resize(n);
    vis.assign(n, 0);
    for (int i = 0; i < m; i++)
    {
        int u = adj[i][0];
        int v = adj[i][1];
        graph[u].push_back(v);
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bfs(i);
        }
    }
    return ans;
}
int main()
{
    int n = 4;
    vector<vector<int>> adj = {
        {0, 1},
        {0, 2},
        {1, 2},
        {2, 3}};
    bfsTraversal(n, adj);
    for (auto a : ans)
    {
        cout << a << " ";
    }
    cout << "\n";
}