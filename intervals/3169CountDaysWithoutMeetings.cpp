#include <bits/stdc++.h>
using namespace std;
#define S second
#define F first
class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        vector<pair<int, int>> events;
        for (auto meeting : meetings)
        {
            events.push_back({meeting[0], 1});
            events.push_back({meeting[1], -1});
        }
        events.push_back({0, 0});
        events.push_back({days + 1, 0});
        sort(events.begin(), events.end());
        int ans = 0;
        int runningMeetings = 0;
        for (int i = 0; i < events.size() - 1; i++)
        {
            runningMeetings += events[i].S;
             if (runningMeetings == 0)
            {
                ans += max(events[i + 1].first - events[i].F - 1, 0);
            }
        }
        return ans;
    }
};
/* class Solution
{
public:
    int n;
    void mark(int start, int end, vector<int> &meetingDays)
    {
        for (int i = start; i <= end; i++)
        {
            meetingDays[i] = 1;
        }
    }
    int countDays(int days, vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end());
        vector<int> meetingDays;
        n = meetings.size();
        meetingDays.resize(days + 1, 0);
        vector<vector<int>> newIntervals;
        int k = 0;
        newIntervals.push_back(meetings[0]);
        for (int i = 1; i < n; i++)
        {
            int start = meetings[i][0];
            int end = meetings[i][1];
            int prevStart = newIntervals[k][0];
            int prevEnd = newIntervals[k][1];
            if (prevEnd >= start)
            {
                newIntervals[k][1] = max(prevEnd, end);
            }
            else
            {
                newIntervals.push_back(meetings[i]);
                k++;
            }
        }
        for (auto interval : newIntervals)
        {
            mark(interval[0], interval[1], meetingDays);
        }
        int c = 0;
        for (int i = 1; i <= n; i++)
        {
            if (meetingDays[i] == 0)
            {
                c++;
            }
        }
        return c;
    }
}; */

int main()
{
    Solution obj;
    vector<vector<int>> meetings = {{2,4}, {1, 3}};
    cout << obj.countDays(10, meetings) << endl;
    return 0;
}