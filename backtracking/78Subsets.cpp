#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<int>> ans;
        int n;
        void rec(int level, vector<int>& nums, vector<int>& temp){
            if(level == n){
                ans.push_back(temp);
                return;
            }
            ans.push_back(temp);
            for(int i = level; i < n; i++){
                temp.push_back(nums[i]);
                rec(i + 1, nums, temp);
                temp.pop_back();
            }
        }
        vector<vector<int>> subsets(vector<int>& nums) {
            n = nums.size();
            vector<int> temp;
            rec(0, nums, temp);
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