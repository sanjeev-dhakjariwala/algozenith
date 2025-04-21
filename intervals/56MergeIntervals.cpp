#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> newIntervals;
        int n = intervals.size();
        newIntervals.push_back(intervals[0]);
        int k = 0;
        for (int i = 1; i < n; i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int prevStart = intervals[k][0];
            int prevEnd = intervals[k][1];
            if (prevEnd >= start)
            {
                newIntervals[k][1] = max(prevEnd, end);
            }
            else
            {
                newIntervals.push_back(intervals[i]);
                k++;
            }
        }
        return newIntervals;
    }
};
int main()
{
    Solution obj;
    vector<vector<int>> intervals = {{1, 4}, {0, 2}, {3, 5}};
    vector<vector<int>> result = obj.merge(intervals);
    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}