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
    int res = 0;
    pair<int,int> dfs(TreeNode* node) {
        if (!node) return {-1, -1};
        auto [ll, lr] = dfs(node->left);
        auto [rl, rr] = dfs(node->right);
        int l = lr + 1, r = rl + 1;
        res = max({res, l, r});
        return {l, r};
    }
    int longestZigZag(TreeNode* root) {
        dfs(root);
        return res;
    }
};
