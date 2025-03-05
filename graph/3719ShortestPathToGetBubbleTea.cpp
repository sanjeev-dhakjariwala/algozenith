#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define F first
#define S second
class Solution
{
public:
    /**
     * @param grid: A m×n character matrix.
     * @return: The length of the shortest path to obtain any cup of bubble tea.
     */
    int row, col;
    bool check(int i, int j, vector<vector<char>> &grid)
    {
        if (i >= 0 && i < row && j >= 0 && j < col && grid[i][j] != 'X')
        {
            return true;
        }
        return false;
    }
    int getBubbleTea(vector<vector<char>> &grid)
    {
        // --- write your code here ---
        ii start;
        row = grid.size();
        col = grid[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '*')
                {
                    start = {i, j};
                }
            }
        }
        vector<vector<int>> dis(row, vector<int>(col, 100));
        vector<vector<int>> vis(row, vector<int>(col, 0));
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push(start);
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        dis[start.F][start.S] = 0;
        while (!pq.empty())
        {
            int x = pq.top().first, y = pq.top().second;
            pq.pop();
            if (vis[x][y])
            {
                continue;
            }
            vis[x][y] = 1;
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (check(nx, ny, grid))
                {
                    if (dis[nx][ny] > dis[x][y] + 1)
                    {
                        dis[nx][ny] = dis[x][y] + 1;
                        pq.push({nx, ny});
                    }
                }
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << dis[i][j] << "\t";
            }
            cout << "\n";
        }
        return 0;
    }
};

int main()
{
    vector<vector<char>> grid = { {'X','X','X','X','X'}, {'X','*','X','O','X'}, {'X','O','X','#','X'}, {'X','X','X','X','X'} };
    Solution obj;
    cout << obj.getBubbleTea(grid);
}