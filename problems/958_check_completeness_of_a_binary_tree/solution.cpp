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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool foundNull = false;
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (!node) foundNull = true;
            else {
                if (foundNull) return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};
