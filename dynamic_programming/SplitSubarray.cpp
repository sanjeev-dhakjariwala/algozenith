#include <bits/stdc++.h>
using namespace std;
int n = 5, k = 3;
vector<int> arr = {1, 3, 2, 5, 4};

int rec(int i, int x)
{
    if (i == -1)
    {
        if (x == 0)
        {
            return 0;
        }
        else
        {
            return 1e9;
        }
    }
    int ans = 1e9;
    int min_seen = arr[i];
    for (int j = i - 1; j >= -1; j--)
    {
        ans = min(ans, rec(j, x - 1) + min_seen);
        min_seen = min(min_seen, arr[j]);
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
    cout << rec(n - 1, k) << endl;
}
int main()
{
    solve();
    return 0;
}