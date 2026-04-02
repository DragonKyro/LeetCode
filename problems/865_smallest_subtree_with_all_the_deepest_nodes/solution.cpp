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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
    pair<TreeNode*, int> dfs(TreeNode* node) {
        if (!node) return {nullptr, 0};
        auto [ln, ld] = dfs(node->left);
        auto [rn, rd] = dfs(node->right);
        if (ld > rd) return {ln, ld + 1};
        if (rd > ld) return {rn, rd + 1};
        return {node, ld + 1};
    }
};
