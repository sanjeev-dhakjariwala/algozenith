#include <bits/stdc++.h>
using namespace std;
/* class Solution
{
public:
    int rec(int level, vector<int> &nums, int dp[])
    {
        if (level < 0)
        {
            return 0;
        }
        if (dp[level] != -1)
        {
            return dp[level];
        }
        int ans = 1;
        for (int prev_taken = 0; prev_taken < level; prev_taken++)
        {
            if (nums[level] > nums[prev_taken])
            {
                int temp = rec(prev_taken, nums, dp);
                ans = max(ans, 1 + temp);
            }
        }
        dp[level] = ans;
        return ans;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        int best = 0;
        int dp[n + 1];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            best = max(best, rec(i, nums, dp));
        }
        return best;
    }
}; */
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> lis;
        for (int i = 0; i < n; i++)
        {
            if (lis.empty() || lis.back() < nums[i])
            {
                lis.push_back(nums[i]);
            }
            else
            {
                auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
                *it = nums[i];
            }
        }
        return lis.size();
    }
};
int main()
{
    Solution obj;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << obj.lengthOfLIS(nums) << endl;
    return 0;
}