#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
#define F first
#define S second
int N, W;
vector<ii> arr; 

int rec(int level, int curr_weight){
	if(level == N){
		return 0;
	}
	int take = 0;
	if(curr_weight <= W){
		take = arr[level].S + rec(level + 1, curr_weight + arr[level].F);
	}
	int not_take = rec(level + 1, curr_weight);
	return max(take, not_take);
}
void solve(){
	cin >> N >> W;
	arr.resize(N);
	for(int i = 0; i < N; i++){
		int w, v;
		cin >> w >> v;
		arr.push_back({w, v});
	}
	int ans = rec(0, 0);
	cout << ans << "\n";
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}