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
    int result = 0;
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return result;
    }
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        int leftPath = (node->left && node->left->val == node->val) ? left + 1 : 0;
        int rightPath = (node->right && node->right->val == node->val) ? right + 1 : 0;
        result = max(result, leftPath + rightPath);
        return max(leftPath, rightPath);
    }
};
