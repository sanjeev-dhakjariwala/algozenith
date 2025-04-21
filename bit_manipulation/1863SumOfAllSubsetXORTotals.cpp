#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int subsetXORSum(vector<int>& nums){
		int n = nums.size();
		int subsets = 1 << n;
		int total = 0;
		
		for(int mask = 0; mask < subsets; mask++){
			int currXOR = 0;
			for(int i = 0; i < n; i++){
				if(mask & (1 << i)){
					currXOR ^= nums[i];
				}
			}
			total += currXOR;
		}
		return total;
	}
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2};
    cout << sol.subsetXORSum(nums) << endl;
    return 0;
}