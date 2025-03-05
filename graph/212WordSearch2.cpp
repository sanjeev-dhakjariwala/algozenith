#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    struct TrieNode
    {
        unordered_map<char, TrieNode *> children;
        string word = "";
    };

    class Trie
    {
    public:
        TrieNode *root;
        Trie() { root = new TrieNode(); }

        void insert(string word)
        {
            TrieNode *node = root;
            for (char c : word)
            {
                if (!node->children.count(c))
                    node->children[c] = new TrieNode();
                node = node->children[c];
            }
            node->word = word; // Store the full word at the leaf node
        }
    };

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        Trie trie;
        for (string &word : words)
            trie.insert(word);

        int rows = board.size(), cols = board[0].size();
        vector<string> result;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (trie.root->children.count(board[i][j]))
                    dfs(board, i, j, trie.root, result);

        return result;
    }

    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *node, vector<string> &result)
    {
        char c = board[i][j];
        if (!node->children.count(c))
            return; // Not a valid prefix

        node = node->children[c];
        if (!node->word.empty())
        {
            result.push_back(node->word);
            node->word = ""; // Avoid duplicates
        }

        board[i][j] = '#';                   // Mark as visited
        vector<int> dir = {-1, 0, 1, 0, -1}; // 4 directions (up, right, down, left)
        for (int d = 0; d < 4; d++)
        {
            int ni = i + dir[d], nj = j + dir[d + 1];
            if (ni >= 0 && ni < board.size() && nj >= 0 && nj < board[0].size() && board[ni][nj] != '#')
                dfs(board, ni, nj, node, result);
        }
        board[i][j] = c; // Restore character

        if (node->children.empty()) // Optimization: Remove dead Trie branches
            node->children.erase(c);
    }
};
int main()
{
    Solution obj;
    vector<vector<char>> board = {{'o', 'a', 'a', 'n'},
                                   {'e', 't', 'a', 'e'},
                                   {'i', 'h', 'k', 'r'},
                                   {'i', 'f', 'l', 'v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};
    vector<string> ans = obj.findWords(board, words);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}   