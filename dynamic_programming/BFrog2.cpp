#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
vector<int> arr;
int rec(int level){
	if(level >= n){
		return 1e9;
	}
	if(level == n - 1){
		return arr[n - 1];
	}
    int cost = 1e9;
	for(int i = 1; i <= k; i++){
		int ans = rec(level + i);
		cost = min(cost, abs(arr[level] - ans));
	}
	return cost;
}
void solve(){
	cin >> n >> k;
	arr.resize(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << rec(0);
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
	t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
