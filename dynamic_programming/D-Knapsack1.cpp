#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
int n, w;
vector<ii> arr;
int rec(int level, int curr_weight){
    if(level == n){
        return 0;
    }
    if(curr_weight > w){
        return 0;
    }
    int taken = arr[level].second + rec(level + 1, curr_weight + arr[level].first);
    int not_taken = rec(level + 1, curr_weight);
    return max(taken, not_taken);
}
void solve(){
    cin >> n >> w;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        int w1, v1;
        cin >> w1 >> v1;
        arr[i] = {w1, v1};
    }
    int ans = rec(0, 0);
    cout << ans << endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}