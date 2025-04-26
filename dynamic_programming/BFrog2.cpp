#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int INF = 1e9;
vector<int> h, dp;
int k;

int solve(int i) {
    if (i == 0) return 0;         // Base case: cost to reach stone 0 is 0
    if (dp[i] != -1) return dp[i]; // Return already computed result

    int cost = INF;
    for (int j = 1; j <= k; ++j) {
        if (i - j >= 0) {
            cost = min(cost, solve(i - j) + abs(h[i] - h[i - j]));
        }
    }

    return dp[i] = cost;
}

int main() {
    int n;
    cin >> n >> k;
    h.resize(n);
    dp.assign(n, -1);

    for (int i = 0; i < n; ++i) cin >> h[i];

    cout << solve(n - 1) << endl;
    return 0;
}
