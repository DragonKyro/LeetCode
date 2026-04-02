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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int left = max(dfs(node->left), 0);
        int right = max(dfs(node->right), 0);
        ans = max(ans, node->val + left + right);
        return node->val + max(left, right);
    }
};
