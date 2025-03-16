#include <bits/stdc++.h>
using namespace std;
int n;
bool rec(int level, int left, vector<int> &arr, int n)
{
    if (left < 0)
    {
        return false;
    }
    if (level == n)
    {
        if (left == 0)
        {
            return true;
        }
        return false;
    }
    int taken = rec(level + 1, left - arr[level], arr, n);
    int not_taken = rec(level + 1, left, arr, n);
    return taken || not_taken;
}
void printset(int level, int left, vector<int>& arr, int n){
    if(level == n){
        return;
    }
    if(rec(level + 1, left, arr, n)){
        printset(level + 1, left, arr, n);
    } else if(rec(level + 1, left - arr[level], arr, n)){
        cout << arr[level] << " ";
        printset(level + 1, left - arr[level], arr, n);
    }
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    n = arr.size();
    return rec(0, k, arr, n);
}
int main()
{
    vector<int> arr = {4, 3, 2, 1};
    if(subsetSumToK(4, 5, arr)){
        printset(0, 5, arr, 4);
        cout << "\n";
    }
    cout << subsetSumToK(4, 5, arr) << endl;
    return 0;
}