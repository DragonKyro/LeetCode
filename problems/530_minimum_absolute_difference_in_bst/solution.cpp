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
    int getMinimumDifference(TreeNode* root) {
        int prev = -1, minDiff = INT_MAX;
        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) return;
            inorder(node->left);
            if (prev >= 0) minDiff = min(minDiff, node->val - prev);
            prev = node->val;
            inorder(node->right);
        };
        inorder(root);
        return minDiff;
    }
};
