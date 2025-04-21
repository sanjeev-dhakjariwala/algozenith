#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define F first
#define S second
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
#define ii pair<int, int>
class Solution
{
public:
    int row, col;
    bool check(int i, int j, vector<vector<int>> &mat)
    {
        if (i >= 0 && i < row && j >= 0 && j < col && mat[i][j] == 1)
        {
            return true;
        }
        return false;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        row = mat.size();
        col = mat[0].size();
        vector<vector<int>> dis(row, vector<int>(col, 1e9));
        queue<ii> q;
        vector<vector<int>> vis(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (mat[i][j] == 0)
                {
                    dis[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            if (vis[x][y])
            {
                continue;
            }
            vis[x][y] = 1;
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (check(nx, ny, mat))
                {
                    if (dis[nx][ny] > dis[x][y] + 1)
                    {
                        dis[nx][ny] = dis[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return dis;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> mat = {{0, 1, 1, 1}, {1, 1, 1, 0}, {1, 1, 1, 1}, {0, 1, 1, 1}};
    vector<vector<int>> ans = s.updateMatrix(mat);
}