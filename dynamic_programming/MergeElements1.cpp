#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int A[501];
int dp[501][501];

int rec(int L, int R){
	if(L == R){
		return 0;
	}
	if(dp[L][R] != -1){
		return dp[L][R];
	}
	int ans = 1e9;
	int tot_sum = 0;
	int left_sum = 0;
	for(int i = L; i <= R; i++){
		tot_sum += A[i];
	}
	for(int mid = L; mid < R; mid++){
		left_sum += A[mid];
		int merge_cost = ((left_sum) % 100 *((tot_sum - left_sum) % 100));
		int half1 = rec(L, mid);
		int half2 = rec(mid + 1, R);
		ans = min(ans, merge_cost + half1 + half2);
	}
	return dp[L][R] = ans;
}
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> A[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << rec(1, n) << "\n";
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
