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
    int ans = INT_MAX;
    int prev = -1;

    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return ans;
    }

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        if (prev >= 0) ans = min(ans, node->val - prev);
        prev = node->val;
        inorder(node->right);
    }
};
