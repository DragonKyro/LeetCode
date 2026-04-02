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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> result;
        dfs(root, true, toDeleteSet, result);
        return result;
    }
    TreeNode* dfs(TreeNode* node, bool isRoot, unordered_set<int>& toDeleteSet, vector<TreeNode*>& result) {
        if (!node) return nullptr;
        bool deleted = toDeleteSet.count(node->val);
        if (isRoot && !deleted) result.push_back(node);
        node->left = dfs(node->left, deleted, toDeleteSet, result);
        node->right = dfs(node->right, deleted, toDeleteSet, result);
        return deleted ? nullptr : node;
    }
};
