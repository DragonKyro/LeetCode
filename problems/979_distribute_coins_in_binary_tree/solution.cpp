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
    int moves = 0;
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int left = dfs(node->left), right = dfs(node->right);
        moves += abs(left) + abs(right);
        return node->val + left + right - 1;
    }
public:
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return moves;
    }
};
