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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return dfs(root, 0, limit);
    }
    TreeNode* dfs(TreeNode* node, long current, int limit) {
        if (!node) return nullptr;
        current += node->val;
        if (!node->left && !node->right)
            return current >= limit ? node : nullptr;
        node->left = dfs(node->left, current, limit);
        node->right = dfs(node->right, current, limit);
        return (!node->left && !node->right) ? nullptr : node;
    }
};
