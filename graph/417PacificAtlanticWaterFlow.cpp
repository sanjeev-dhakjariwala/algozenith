#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<int>> result;

        for (int i = 0; i < m; i++)
        {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }

        for (int j = 0; j < n; j++)
        {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m - 1, j);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

private:
    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &ocean, int i, int j)
    {
        int m = heights.size();
        int n = heights[0].size();
        ocean[i][j] = true;
        vector<int> dirs = {0, 1, 0, -1, 0};

        for (int d = 0; d < 4; d++)
        {
            int ni = i + dirs[d];
            int nj = j + dirs[d + 1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && !ocean[ni][nj] && heights[ni][nj] >= heights[i][j])
            {
                dfs(heights, ocean, ni, nj);
            }
        }
    }
};
int main()
{
    Solution s;
    vector<vector<int>> heights = {{1, 2, 2, 3, 5},
                                   {3, 2, 3, 4, 4},
                                   {2, 4, 5, 3, 1},
                                   {6, 7, 1, 4, 5},
                                   {5, 1, 1, 2, 4}};
    vector<vector<int>> result = s.pacificAtlantic(heights);
    for (auto x : result)
    {
        cout << x[0] << " " << x[1] << endl;
    }
    return 0;
}