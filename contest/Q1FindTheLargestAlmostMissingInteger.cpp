#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int largestInteger(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> sub_array;
        map<int, int> mp_sub;
        for (int i = 0; i <= n - k; i++)
        {
            vector<int> temp;
            set<int> st;
            for (int j = 0; j < k; j++)
            {
                if (i + j >= n)
                {
                    break;
                }
                if(st.find(nums[i + j]) == st.end()){
                    mp_sub[nums[i + j]]++;
                    st.insert(nums[i + j]);
                }
                temp.push_back(nums[i + j]);
            }
            sub_array.push_back(temp);
        }
        vector<int> ans;
        for (auto s : sub_array)
        {
            map<int, int> mp;
            if (s.size() == k)
            {
                for (auto a : s)
                {
                    mp[a]++;
                }
            }
            for (auto t : mp)
            {
                if (mp_sub[t.first] == 1 && t.second == 1)
                {
                    ans.push_back(t.first);
                }
            }
        }
        sort(ans.begin(), ans.end());
        if(ans.size() >= 1)
            return ans[ans.size() - 1];
        else
            return -1;
    }
};
int main()
{
    Solution obj;
    vector<int> nums = {3,9,2,1,7};
    int k = 4;
    cout << obj.largestInteger(nums, k);
    return 0;
}