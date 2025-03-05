#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int max_coins = INT_MIN;

    void rec(int i, int j, int temp, int neut, int row, int col, vector<vector<int>> &coins)
    {
        if (i >= row || i < 0 || j >= col || j < 0)
        {
            return;
        }
        if (i == row - 1 && j == col - 1)
        {
            max_coins = max(max_coins, temp);
            return;
        }
        if (coins[i][j] < 0)
        {
            if (neut > 0)
            {
                rec(i + 1, j, temp, neut - 1, row, col, coins);
                rec(i, j + 1, temp, neut - 1, row, col, coins);
            }
            else
            {
                rec(i + 1, j, temp + coins[i][j], neut, row, col, coins);
                rec(i, j + 1, temp + coins[i][j], neut, row, col, coins);
            }
        }
        else
        {
            rec(i + 1, j, temp + coins[i][j], neut, row, col, coins);
            rec(i, j + 1, temp + coins[i][j], neut, row, col, coins);
        }
    }

    int maxCoins(vector<vector<int>> &coins, int neut)
    {
        int row = coins.size();
        int col = coins[0].size();
        rec(0, 0, 0, neut, row, col, coins);
        return max_coins;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> coins = {{0, 1, -1}, {1, -2, 3}, {2, -3, 4}};
    cout << s.maximumAmount(coins) << endl;
    return 0;
}