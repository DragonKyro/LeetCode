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
    int pseudoPalindromicPaths(TreeNode* root) {
        return dfs(root, 0);
    }
    int dfs(TreeNode* node, int mask) {
        if (!node) return 0;
        mask ^= 1 << node->val;
        if (!node->left && !node->right) return (mask & (mask - 1)) == 0 ? 1 : 0;
        return dfs(node->left, mask) + dfs(node->right, mask);
    }
};
