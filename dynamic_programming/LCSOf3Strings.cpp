#include <bits/stdc++.h>
using namespace std;
#define int long long
string a, b, c;
int dp[101][101][101];
int rec(int i, int j, int k)
{
    if (i < 0 || j < 0 || k < 0)
    {
        return 0;
    }
    if (dp[i][j][k] != -1)
    {
        return dp[i][j][k];
    }
    int ans = 0;
    if ((a[i] == b[j]) && (b[j] == c[k]))
    {
        ans = 1 + rec(i - 1, j - 1, k - 1);
    }
    ans += rec(i - 1, j, k);
    ans += rec(i, j - 1, k);
    ans += rec(i, j, k - 1);
    return dp[i][j][k] = ans;
}
void solve()
{
    cin >> a >> b >> c;
    int l1 = a.size();
    int l2 = b.size();
    int l3 = c.size();
    memset(dp, -1, sizeof(dp));
    cout << rec(l1 - 1, l2 - 1, l3 - 1) << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}