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
    int idx = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MAX);
    }
    TreeNode* build(vector<int>& preorder, int bound) {
        if (idx >= preorder.size() || preorder[idx] > bound) return nullptr;
        TreeNode* node = new TreeNode(preorder[idx++]);
        node->left = build(preorder, node->val);
        node->right = build(preorder, bound);
        return node;
    }
};
