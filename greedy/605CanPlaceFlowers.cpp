#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int s = flowerbed.size();
        for (int i = 0; i < s; i++)
        {
            if (i + 1 < s)
            {
                if ((flowerbed[i] == 1 && flowerbed[i + 1] == 0))
                {
                    flowerbed[i + 1] = 1e9;
                }
                if (flowerbed[i] == 0 && flowerbed[i + 1] == 1)
                {
                    flowerbed[i] = 1e9;
                }
            }
        }
        int c = 0;
        for (int i = 0; i < s; i++)
        {
            if (flowerbed[i] == 0)
            {
                c++;
            }
        }
        return c >= n;
    }
};
int main()
{
    Solution s;
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    cout << s.canPlaceFlowers(flowerbed, 2) << endl;
    return 0;
}