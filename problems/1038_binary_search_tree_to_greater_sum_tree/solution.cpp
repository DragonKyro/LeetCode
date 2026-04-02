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
    int total = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if (root) {
            bstToGst(root->right);
            total += root->val;
            root->val = total;
            bstToGst(root->left);
        }
        return root;
    }
};
