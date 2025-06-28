#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges)
    {
        // Code here
        vector<int> dist(n, 0);
        for (int i = 0; i < n - 1; i++)
        {
            bool changed = false;
            for (auto e : edges)
            {
                int u = e[0], v = e[1], w = e[2];
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    changed = true;
                }
            }
            if (!changed)
            {
                break;
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            for (auto e : edges)
            {
                int u = e[0], v = e[1], w = e[2];
                if (dist[v] > dist[u] + w)
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};
int main()
{
    int n, m;
    vector<vector<int>> edges = {{0, 1, -1}, {1, 2, -2}, {2, 0, -3}};
    n = 3; // Number of vertices
    m = edges.size(); // Number of edges
    Solution obj;
    cout << obj.isNegativeWeightCycle(n, edges) << endl;
    return 0;
}