#include <bits/stdc++.h>
using namespace std;
int n;
bool rec(int level, int left, vector<int>& arr, int n){
    if(left < 0){
        return false;
    }
    if(left == 0){
        return true;
    }
    if(level == n){
        return false;
    }
    int taken = rec(level + 1, left - arr[level], arr, n);
    int not_taken = rec(level + 1, left, arr, n);
    return taken || not_taken;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    n = arr.size();
    return rec(0, k, arr, n);
}
int main(){
    vector<int> arr = {4, 3, 2, 1};
    cout << subsetSumToK(4, 5, arr) << endl;
    return 0;
}