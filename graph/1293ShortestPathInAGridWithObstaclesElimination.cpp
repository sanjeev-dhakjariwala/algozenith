#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define state pair<pair<int, int>, int>
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
class Solution
{
public:
    int rows, cols;
    bool check(int x, int y)
    {
        if (x >= 0 && x < rows && y >= 0 && y < cols)
        {
            return true;
        }
        return false;
    }
    vector<state> getNeighbors(state s, vector<vector<int>> &grid)
    {
        vector<state> ans;
        for (int i = 0; i < 4; i++)
        {
            int nx = s.F.F + dx[i];
            int ny = s.F.S + dy[i];
            int z = s.S;
            if (check(nx, ny))
            {
                if (grid[nx][ny] == 1)
                {
                    z++;
                }
                ans.push_back({{nx, ny}, z});
            }
        }
        return ans;
    }
    int shortestPath(vector<vector<int>> &grid, int k)
    {
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<vector<int>>> dis(rows, vector<vector<int>>(cols, vector<int>(rows + cols, 1e9)));
        vector<vector<vector<int>>> vis(rows, vector<vector<int>>(cols, vector<int>(rows + cols, 0)));
        queue<state> q;
        q.push({{0, 0}, 0});
        dis[0][0][0] = 0;
        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            int x = t.F.F;
            int y = t.F.S;
            int z = t.S;
            if (vis[x][y][z])
            {
                continue;
            }
            vis[x][y][z] = 1;
            for (auto n : getNeighbors(t, grid))
            {
                if (n.S < (rows + cols) && dis[n.F.F][n.F.S][n.S] > 1 + dis[x][y][z])
                {
                    dis[n.F.F][n.F.S][n.S] = 1 + dis[x][y][z];
                    q.push(n);
                }
            }
        }
        int ans = 1e9;
        for (int i = 0; i <= k; i++)
        {
            ans = min(ans, dis[rows - 1][cols - 1][i]);
        }
        return ans == 1e9 ? -1 : ans;
    }
};
int main()
{
    vector<vector<int>> grid = {{0}};
    Solution obj;
    cout << obj.shortestPath(grid, 1) << endl;
    return 0;
}