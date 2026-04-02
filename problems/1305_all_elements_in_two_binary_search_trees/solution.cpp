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
    void inorder(TreeNode* node, vector<int>& res) {
        if (!node) return;
        inorder(node->left, res); res.push_back(node->val); inorder(node->right, res);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> l1, l2;
        inorder(root1, l1); inorder(root2, l2);
        vector<int> res;
        merge(l1.begin(), l1.end(), l2.begin(), l2.end(), back_inserter(res));
        return res;
    }
};
