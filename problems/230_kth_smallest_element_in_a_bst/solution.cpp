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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        while (!stk.empty() || curr) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top(); stk.pop();
            if (--k == 0) return curr->val;
            curr = curr->right;
        }
        return -1;
    }
};
