#include <bits/stdc++.h>
using namespace std;
class UnionFind
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if (x != parent[x])
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
        {
            return false;
        }
        if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else if (rank[rootY] > rank[rootX])
        {
            parent[rootX] = rootY;
        }
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        UnionFind uf(n);
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            if (!uf.unite(u, v))
            {
                return edge;
            }
        }
        return {};
    }
};
int main(){
    Solution s;
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
    vector<int> ans = s.findRedundantConnection(edges);
    for(auto &x: ans){
        cout<<x<<" ";
    }
    return 0;
}