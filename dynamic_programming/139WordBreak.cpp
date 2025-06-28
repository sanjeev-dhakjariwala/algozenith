#include <bits/stdc++.h>
using namespace std;
/* class Solution
{
public:
    int n;
    vector<int> dp;
    unordered_set<string> dict;
    int rec(int i, string &s)
    {
        if (i > n)
        {
            return 0;
        }
        if (i == n)
        {
            return 1;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        for (int j = i + 1; j <= n; j++)
        {
            string temp = s.substr(i, j - i);
            cout << temp << "\n";
            if (dict.count(temp) && rec(j, s))
            {
                return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        n = s.size();
        dp.resize(n + 1, -1);
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        return rec(0, s);
    }
}; */
class Solution
{
public:
    int n;
    int rec(int level, string s, unordered_set<string> &setDict)
    {
        if (level == n)
        {
            return false;
        }
        for (int i = level; i < n; i++)
        {
            string str = s.substr(level, i - level + 1);
            if (setDict.count(str) && rec(i + 1, s, setDict))
            {
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> setDict(wordDict.begin(), wordDict.end());
        return rec(0, s, setDict);
    }
};
int main()
{
    Solution sol;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << sol.wordBreak(s, wordDict);
    return 0;
}