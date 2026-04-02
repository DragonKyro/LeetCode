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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        queue<TreeNode*> q;
        q.push(root);
        for (int i = 0; i < depth - 2; i++) {
            int sz = q.size();
            for (int j = 0; j < sz; j++) {
                TreeNode* node = q.front(); q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            TreeNode* left = new TreeNode(val);
            left->left = node->left;
            node->left = left;
            TreeNode* right = new TreeNode(val);
            right->right = node->right;
            node->right = right;
        }
        return root;
    }
};
