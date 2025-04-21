#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findPlatform(vector<int> &arr, vector<int> &dep)
    {
        int n = arr.size();

        // Validate input
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > dep[i])
            {
                cout << "Invalid input: arr[" << i << "] = " << arr[i]
                     << " > dep[" << i << "] = " << dep[i] << endl;
                return -1;
            }
        }

        vector<pair<int, int>> events; // {time, type} where 1 = arrival, 0 = departure
        for (int i = 0; i < n; i++)
        {
            events.push_back({arr[i], 1}); // Arrival
            events.push_back({dep[i], 0}); // Departure
        }

        // Sort: if times equal, arrivals (1) before departures (0)
        sort(events.begin(), events.end(), [](pair<int, int> a, pair<int, int> b)
             {
              if (a.first == b.first) return a.second > b.second; // 1 > 0
              return a.first < b.first; });

        int currPlatforms = 0, maxPlatforms = 0;
        cout << "Sweeping events:\n";
        for (auto event : events)
        {
            if (event.second == 1)
            {
                currPlatforms++;
                cout << "Time " << event.first << ": Arrival, Platforms = " << currPlatforms << endl;
            }
            else
            {
                currPlatforms--;
                cout << "Time " << event.first << ": Departure, Platforms = " << currPlatforms << endl;
            }
            maxPlatforms = max(maxPlatforms, currPlatforms);
        }

        return maxPlatforms;
    }
};
int main()
{
    vector<int> arr = {2225, 1729, 1835, 951, 1143, 515, 1525, 743, 1025, 1611, 1827, 2203, 1116, 1514, 723};
    vector<int> dep = {2231, 2003, 2149, 2252, 2352, 2153, 1625, 1049, 1337, 1639, 2151, 2330, 1633, 1611, 2009};
    Solution obj;
    cout << obj.findPlatform(arr, dep);
}