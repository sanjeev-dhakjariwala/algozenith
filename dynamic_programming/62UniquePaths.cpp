#include <bits/stdc++.h>
using namespace std;
/* class Solution
{
public:
    int rec(int i, int j, int m, int n)
    {
        if (i > m || j > n)
        {
            return 0;
        }
        if (i == m && j == n)
        {
            return 1;
        }
        int down = rec(i + 1, j, m, n);
        int right = rec(i, j + 1, m, n);
        return down + right;
    }
    int uniquePaths(int m, int n)
    {
        return rec(1, 1, m, n);
    }
}; */
class Solution
{
public:
    vector<vector<int>> dp;
    int uniquePaths(int m, int n)
    {
        dp.resize(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++)
        {
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
int main()
{
    Solution obj;
    cout << obj.uniquePaths(3, 7) << endl;
    return 0;
}