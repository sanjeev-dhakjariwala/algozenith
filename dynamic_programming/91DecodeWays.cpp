#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n;
    string s;
    int rec(int level)
    {
        if (level == n)
        {
            return 0;
        }
        if (s[level] == '0')
        {
            return 0;
        }
        int temp = 1 + rec(level + 1);
        if (level + 1 < n)
        {
            int n = (10 * stoi(string("") + s[level])) + (stoi(string("") + s[level + 1]));
            if (n >= 10 && n <= 26)
            {
                temp += rec(level + 2);
            }
        }
        return temp;
    }
    int numDecodings(string s)
    {
        n = s.size();
        this->s = s;
        return rec(0);
    }
};
int main()
{
    Solution sol;
    string s = "226";
    cout << sol.numDecodings(s) << endl; // Output: 3
    // s = "12";
    // cout << sol.numDecodings(s) << endl; // Output: 2
    // s = "0";
    // cout << sol.numDecodings(s) << endl; // Output: 0
    // s = "06";
    // cout << sol.numDecodings(s) << endl; // Output: 0
    return 0;
}