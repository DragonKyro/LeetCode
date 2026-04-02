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
    bool dfs(ListNode* head, TreeNode* node) {
        if (!head) return true;
        if (!node) return false;
        if (head->val == node->val) return dfs(head->next, node->left) || dfs(head->next, node->right);
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
