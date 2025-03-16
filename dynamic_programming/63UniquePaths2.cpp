#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<int>> dp;
        dp.resize(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++)
        {
            if(obstacleGrid[i][0] == 0){
                dp[i][0] = 1;
            }
        }
        for (int j = 0; j < cols; j++)
        {
            if(obstacleGrid[0][j] == 0){
                dp[0][j] = 1;
            }
        }
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[rows - 1][cols - 1];
    }
};
int main()
{
    Solution obj;
    vector<vector<int>> obstacleGrid = {{1,0}};
    cout << obj.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}