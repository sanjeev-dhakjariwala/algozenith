#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsetSum(vector<int> &arr, int target)
    {
        // code here
        int n = arr.size();
        vector<bool> dp(target + 1, false);
        dp[0] = true; // Base case: subset sum of 0 is always possible

        for (int num : arr)
        {
            for (int j = target; j >= num; j--)
            {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }
};

int main()
{
    vector<int> arr = {4, 3, 2, 1};
    Solution obj;
    cout << obj.isSubsetSum(arr, 5) << endl;
    return 0;
}