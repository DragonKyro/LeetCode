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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    int dfs(TreeNode* node, int current) {
        if (!node) return 0;
        current = current * 10 + node->val;
        if (!node->left && !node->right) return current;
        return dfs(node->left, current) + dfs(node->right, current);
    }
};
