#include<bits/stdc++.h>
using namespace std;
#define int long long
int min_steps = INT_MAX;
void rec(int curr, int arr[], int n, vector<int>& temp){
    if(curr >= n){
        min_steps = min(min_steps, (int) temp.size());
        return;
    }
    for(int i = 0; i < 2; i++){
        temp.push_back(arr[i]);
        rec(curr + arr[i], arr, n, temp);
        temp.pop_back();
    }
}
void solve(){
    int n = 6; 
    int m = 4;
    //cin >> n >> m;
    int arr[] = {1, m};
    vector<int> temp;
    rec(0, arr, n, temp);
    cout << min_steps;
    min_steps = INT_MAX;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}