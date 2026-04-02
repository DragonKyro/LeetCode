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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1, l2;
        leaves(root1, l1); leaves(root2, l2);
        return l1 == l2;
    }
    void leaves(TreeNode* node, vector<int>& list) {
        if (!node) return;
        if (!node->left && !node->right) { list.push_back(node->val); return; }
        leaves(node->left, list); leaves(node->right, list);
    }
};
