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
    bool evaluateTree(TreeNode* root) {
        if (!root->left) return root->val == 1;
        bool left = evaluateTree(root->left), right = evaluateTree(root->right);
        return root->val == 2 ? left || right : left && right;
    }
};
