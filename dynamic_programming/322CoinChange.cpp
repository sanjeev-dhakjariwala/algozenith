#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<int> coins;
    int dp[10001];
    int rec(int left){
        if(left < 0){
            return -1;
        }
        if(left == 0){
            return 0;
        }
        if(dp[left] != -1){
            return dp[left];
        }
        int res = 1e9;
        for(auto coin: coins){
            int temp = rec(left - coin);
            if(temp != -1){
                res = min(res, 1 + temp);
            }
        }
        return dp[left] = res;
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        this->coins = coins;
        memset(dp, -1, sizeof(dp));
        int ans = rec(amount);
        return ans != 1e9 ?  ans: -1;
    }
};
int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << sol.coinChange(coins, amount) << endl; // Output: 3
    return 0;
}
