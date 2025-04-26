#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
class Solution
{
public:
    int distinctSubseqII(string s)
    {
        int n = s.size();
        int prefix[n + 1];
        int dp[n + 1];
        int last[26];
        memset(last, -1, sizeof(last));
        dp[0] = 1;
        prefix[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = prefix[i - 1];
            if (last[s[i - 1] - 'a'] != -1)
            {
                dp[i] = (dp[i] - prefix[last[s[i - 1] - 'a']] + MOD) % MOD;
            }
            last[s[i - 1] - 'a'] = i - 1;
            prefix[i] = (prefix[i - 1] + dp[i]) % MOD;
        }
        return (prefix[n] - 1 + MOD) % MOD;
    }
};
int main(){
    Solution sol;
    string s = "aba";
    cout << sol.distinctSubseqII(s);
    return 0;
}