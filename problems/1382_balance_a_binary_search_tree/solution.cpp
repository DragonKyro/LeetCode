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
    vector<int> nodes;
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left); nodes.push_back(node->val); inorder(node->right);
    }
    TreeNode* build(int lo, int hi) {
        if (lo > hi) return nullptr;
        int mid = (lo + hi) / 2;
        auto node = new TreeNode(nodes[mid]);
        node->left = build(lo, mid - 1);
        node->right = build(mid + 1, hi);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return build(0, nodes.size() - 1);
    }
};
