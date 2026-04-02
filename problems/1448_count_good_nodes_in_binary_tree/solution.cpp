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
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
    int dfs(TreeNode* node, int maxVal) {
        if (!node) return 0;
        int count = node->val >= maxVal ? 1 : 0;
        int newMax = max(maxVal, node->val);
        return count + dfs(node->left, newMax) + dfs(node->right, newMax);
    }
};
