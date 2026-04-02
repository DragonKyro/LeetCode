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
    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root, 1, 1);
    }
    int dfs(TreeNode* node, int parent, int grandparent) {
        if (!node) return 0;
        int total = grandparent % 2 == 0 ? node->val : 0;
        total += dfs(node->left, node->val, parent);
        total += dfs(node->right, node->val, parent);
        return total;
    }
};
