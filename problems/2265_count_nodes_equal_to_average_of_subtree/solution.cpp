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
    int count = 0;
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count;
    }
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        auto [ls, lc] = dfs(node->left);
        auto [rs, rc] = dfs(node->right);
        int sum = ls + rs + node->val;
        int cnt = lc + rc + 1;
        if (sum / cnt == node->val) count++;
        return {sum, cnt};
    }
};
