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
    int leftCount = 0, rightCount = 0;
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        find(root, x);
        int parentCount = n - leftCount - rightCount - 1;
        return max({leftCount, rightCount, parentCount}) > n / 2;
    }
    int count(TreeNode* node) {
        if (!node) return 0;
        return 1 + count(node->left) + count(node->right);
    }
    void find(TreeNode* node, int x) {
        if (!node) return;
        if (node->val == x) {
            leftCount = count(node->left);
            rightCount = count(node->right);
            return;
        }
        find(node->left, x);
        find(node->right, x);
    }
};
