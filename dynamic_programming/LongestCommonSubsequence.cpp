#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lcs(string &s1, string &s2)
    {
        // code here
        int l1 = s1.length();
        int l2 = s2.length();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

        for (int i = 1; i <= l1; i++)
        {
            for (int j = 1; j <= l2; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[l1][l2];
    }
};

int main()
{
    Solution obj;
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";
    cout << obj.lcs(s1, s2) << endl;
    return 0;
}