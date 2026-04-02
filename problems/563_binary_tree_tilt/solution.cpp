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
    int tilt = 0;
    int findTilt(TreeNode* root) {
        dfs(root);
        return tilt;
    }
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int left = dfs(node->left), right = dfs(node->right);
        tilt += abs(left - right);
        return node->val + left + right;
    }
};
