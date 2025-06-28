#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dp;
    vector<int> arr;
    int rec(int level, int prev)
    {
        if (level == -1)
        {
            return 0;
        }
        if (dp[level] != -1)
        {
            return dp[level];
        }
        int ans1 = 0;
        if (prev == -1 || arr[level] >= arr[prev])
        {
            ans1 = 1 + rec(level - 1, level);
        }
        int ans2 = rec(level - 1, prev);
        return max(ans1, ans2);
    }
    int lengthOfLIS(vector<int> &nums)
    {
        arr = nums;
        int n = nums.size();
        dp.resize(n + 1, -1);
        return rec(n - 1, -1);
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {0, 1, 0, 3, 2, 3};
    cout << sol.lengthOfLIS(arr);
    return 0;
}