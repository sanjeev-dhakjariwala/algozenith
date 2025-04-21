#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dp[100][100]; // Memo table (simplified 2D, adjust for k)
    int solve(vector<int> &cardPoints, int i, int j, int k)
    {
        if (k == 0)
            return 0;
        if (i > j)
            return 0;
        if (i == j && k == 1)
            return cardPoints[i];
        if (dp[i][j] != -1)
            return dp[i][j]; // Assuming k is fixed or tracked separately

        int left = cardPoints[i] + solve(cardPoints, i + 1, j, k - 1);
        int right = cardPoints[j] + solve(cardPoints, i, j - 1, k - 1);
        return dp[i][j] = max(left, right);
    }
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        memset(dp, -1, sizeof(dp));
        return solve(cardPoints, 0, n - 1, k);
    }
};
int main()
{
    Solution sol;
    vector<int> p = {1, 2, 3, 4, 5, 6, 1};
    int ans = sol.maxScore(p, 3);
    cout << ans << "\n";
    return 0;
}