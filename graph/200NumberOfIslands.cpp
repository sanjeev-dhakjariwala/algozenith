#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int row, col;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    vector<vector<int>> vis;
    bool check(int x, int y, vector<vector<char>> &grid)
    {
        if (x >= 0 && x < row && y >= 0 && y < col && grid[x][y] == '1')
        {
            return true;
        }
        return false;
    }
    void dfs(int x, int y, vector<vector<char>> &grid)
    {
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (check(nx, ny, grid))
            {
                if (!vis[nx][ny])
                {
                    dfs(nx, ny, grid);
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        row = grid.size();
        col = grid[0].size();
        int island = 0;
        vis.resize(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1')
                {
                    if (!vis[i][j])
                    {
                        dfs(i, j, grid);
                        island++;
                    }
                }
            }
        }
        return island;
    }
};
int main(){
    Solution s;
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    cout << s.numIslands(grid) << endl;
    return 0;
}
