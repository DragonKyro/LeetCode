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
    bool isCousins(TreeNode* root, int x, int y) {
        int dx = 0, dy = 0;
        TreeNode *px = nullptr, *py = nullptr;
        dfs(root, nullptr, 0, x, dx, px);
        dfs(root, nullptr, 0, y, dy, py);
        return dx == dy && px != py;
    }
    void dfs(TreeNode* node, TreeNode* parent, int depth, int target, int& d, TreeNode*& p) {
        if (!node) return;
        if (node->val == target) { d = depth; p = parent; return; }
        dfs(node->left, node, depth + 1, target, d, p);
        dfs(node->right, node, depth + 1, target, d, p);
    }
};
