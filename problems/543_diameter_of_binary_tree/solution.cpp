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
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return ans;
    }
    int depth(TreeNode* node) {
        if (!node) return 0;
        int left = depth(node->left), right = depth(node->right);
        ans = max(ans, left + right);
        return 1 + max(left, right);
    }
};
