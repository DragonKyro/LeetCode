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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }
    pair<int, TreeNode*> dfs(TreeNode* node) {
        if (!node) return {0, nullptr};
        auto [ld, ll] = dfs(node->left);
        auto [rd, rl] = dfs(node->right);
        if (ld == rd) return {ld + 1, node};
        if (ld > rd) return {ld + 1, ll};
        return {rd + 1, rl};
    }
};
