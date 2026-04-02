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
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
    int dfs(TreeNode* node, int mn, int mx) {
        if (!node) return mx - mn;
        mn = min(mn, node->val);
        mx = max(mx, node->val);
        return max(dfs(node->left, mn, mx), dfs(node->right, mn, mx));
    }
};
