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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        dfs(root, "", res);
        return res;
    }

    void dfs(TreeNode* node, string path, vector<string>& res) {
        if (!node->left && !node->right) {
            res.push_back(path + to_string(node->val));
            return;
        }
        if (node->left) dfs(node->left, path + to_string(node->val) + "->", res);
        if (node->right) dfs(node->right, path + to_string(node->val) + "->", res);
    }
};
