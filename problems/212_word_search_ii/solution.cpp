#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#include <set>
#include <map>
using namespace std;

class Solution {
    struct TrieNode {
        TrieNode* children[26] = {};
        string word;
    };
    vector<string> res;
    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a']) return;
        node = node->children[c - 'a'];
        if (!node->word.empty()) {
            res.push_back(node->word);
            node->word.clear();
        }
        board[i][j] = '#';
        for (auto& d : dirs) dfs(board, i + d[0], j + d[1], node);
        board[i][j] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (auto& w : words) {
            TrieNode* node = root;
            for (char c : w) {
                int idx = c - 'a';
                if (!node->children[idx]) node->children[idx] = new TrieNode();
                node = node->children[idx];
            }
            node->word = w;
        }
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                dfs(board, i, j, root);
        return res;
    }
};
