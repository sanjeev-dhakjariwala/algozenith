#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
class Solution {
public:
    int rows, cols;
    vector<vector<int>> vis;
    bool check(int i, int j) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            return true;
        }
        return false;
    }
    bool dfs(int i, int j, vector<vector<char>>& board, string word, int curr) {
        if (curr == word.size()) {
            return true;
        }
        if (word[curr] != board[i][j]) {
            return false;
        }
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (check(ni, nj) && !vis[ni][nj]) {
                vis[ni][nj] = 1;
                if (dfs(ni, nj, board, word, curr + 1)) {
                    return true; // Correct: return true if any neighbor fin the word
                }
                vis[ni][nj] = 0; // Correct: backtracking
            }
        }
        vis[i][j] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        vis.resize(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(i, j, board, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    Solution obj;
    vector<vector<char>> board = {{'a'}};
    string word = "a";
    cout << obj.exist(board, word) << endl;
    return 0;
}