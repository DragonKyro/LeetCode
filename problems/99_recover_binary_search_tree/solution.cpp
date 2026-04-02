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
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while (curr || !st.empty()) {
            while (curr) { st.push(curr); curr = curr->left; }
            curr = st.top(); st.pop();
            if (prev && prev->val > curr->val) {
                if (!first) first = prev;
                second = curr;
            }
            prev = curr;
            curr = curr->right;
        }
        swap(first->val, second->val);
    }
};
