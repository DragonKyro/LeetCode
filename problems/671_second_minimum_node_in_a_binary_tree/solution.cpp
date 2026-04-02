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
    int findSecondMinimumValue(TreeNode* root) {
        long result = LONG_MAX;
        int minVal = root->val;
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return;
            if (node->val > minVal && node->val < result) {
                result = node->val;
            } else if (node->val == minVal) {
                dfs(node->left);
                dfs(node->right);
            }
        };
        dfs(root);
        return result == LONG_MAX ? -1 : result;
    }
};
