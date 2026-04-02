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
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        if (root->left && root->left->val != root->val) return false;
        if (root->right && root->right->val != root->val) return false;
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};
