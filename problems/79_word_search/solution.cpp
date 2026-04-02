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
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(board, word, i, j, 0)) return true;
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
        if (k == (int)word.size()) return true;
        if (i < 0 || i >= (int)board.size() || j < 0 || j >= (int)board[0].size() || board[i][j] != word[k]) return false;
        char temp = board[i][j];
        board[i][j] = '#';
        bool found = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) ||
                     dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1);
        board[i][j] = temp;
        return found;
    }
};
