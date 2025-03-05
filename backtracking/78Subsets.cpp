#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rec(int level, vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp){
        if(temp.size() <= 2){
            ans.push_back(temp);
            return;
        }
        if(level >= nums.size()){
            return;
        }
        temp.push_back(nums[level]);
        rec(level + 1, nums, ans, temp);
        temp.pop_back();
        rec(level + 1, nums, ans, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        rec(0, nums, ans, temp);
        return ans;
    }
};
int main(){
    Solution obj;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = obj.subsets(nums);
    for(auto x: ans){
        for(auto y: x){
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}