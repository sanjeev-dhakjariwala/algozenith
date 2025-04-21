#include<bits/stdc++.h>
using namespace std;
#define lli long long

lli sum_of_bit(lli x){
	lli ans = 0;
	lli tot = x + 1;
	for(int i = 0; i <= 60; i++){
		lli full = (tot / (1LL << (i + 1)));
		lli left = tot % (1LL << (i + 1));
		lli extra = max(left - (1LL << i), 0LL);
		ans += full * (1LL << i) + extra; 
	}
	return ans;
}
void solve(){
	cout << sum_of_bit(3) << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
