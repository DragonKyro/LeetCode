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
    vector<int> findMode(TreeNode* root) {
        vector<int> modes;
        int prev = INT_MIN, count = 0, maxCount = 0;
        bool hasPrev = false;
        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) return;
            inorder(node->left);
            if (hasPrev && prev == node->val) count++;
            else count = 1;
            if (count > maxCount) {
                maxCount = count;
                modes.clear();
                modes.push_back(node->val);
            } else if (count == maxCount) {
                modes.push_back(node->val);
            }
            prev = node->val;
            hasPrev = true;
            inorder(node->right);
        };
        inorder(root);
        return modes;
    }
};
