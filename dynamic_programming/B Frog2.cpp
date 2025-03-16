#include <bits/stdc++.h>
using namespace std;

int n = 5, k = 3;
vector<int> arr = {10, 30, 40, 50, 20};

int rec(int level)
{
    if (level == n)
    {
        return 0;
    }
    int ans = 1e9;
    for (int i = 1; i <= k; i++)
    {
        if (level + i <= n)
        {
            ans = min(ans, rec(level + i) + abs(arr[level] - arr[level + i]));
        }
    }
    return ans;
}
void solve()
{
    // cin >> n >> k;
    // arr.resize(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    cout << rec(0);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}