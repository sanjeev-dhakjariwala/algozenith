#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
vector<vector<int>> dp;
int rec(int level, int k)
{
    if (k == 0)
    {
        if (level == 0)
        {
            return 1;
        }
        return 0;
    }
    if (level == -1)
    {
        return 0;
    }
    if (dp[level][k] != -1)
    {
        return dp[level][k];
    }
    int ans = 0;
    for (int i = 1; i <= level; i++)
    {
        int temp = rec(level - i, k - 1);
        ans += temp;
    }
    return dp[level][k] = ans;
}
void solve()
{
    cin >> n >> k;
    dp.assign(n + 1, vector<int>(k + 1, -1));
    cout << rec(n, k) << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}