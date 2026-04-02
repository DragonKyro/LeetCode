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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root); root->val = 0;
        while (!q.empty()) {
            int sz = q.size(); long long sum = 0;
            vector<TreeNode*> nodes;
            for (int i = 0; i < sz; i++) {
                auto n = q.front(); q.pop(); nodes.push_back(n);
                if (n->left) { sum += n->left->val; q.push(n->left); }
                if (n->right) { sum += n->right->val; q.push(n->right); }
            }
            for (auto n : nodes) {
                int sib = (n->left?n->left->val:0)+(n->right?n->right->val:0);
                if (n->left) n->left->val = sum-sib;
                if (n->right) n->right->val = sum-sib;
            }
        }
        return root;
    }
};
