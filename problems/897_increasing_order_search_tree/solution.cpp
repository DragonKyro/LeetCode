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
    TreeNode* curr;
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode dummy(0);
        curr = &dummy;
        inorder(root);
        return dummy.right;
    }
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        node->left = nullptr;
        curr->right = node;
        curr = node;
        inorder(node->right);
    }
};
