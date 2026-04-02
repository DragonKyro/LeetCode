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
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        int cols = (1 << h) - 1;
        vector<vector<string>> result(h, vector<string>(cols, ""));
        fill(root, 0, 0, cols - 1, result);
        return result;
    }
    int height(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }
    void fill(TreeNode* node, int r, int lo, int hi, vector<vector<string>>& result) {
        if (!node) return;
        int mid = (lo + hi) / 2;
        result[r][mid] = to_string(node->val);
        fill(node->left, r + 1, lo, mid - 1, result);
        fill(node->right, r + 1, mid + 1, hi, result);
    }
};
