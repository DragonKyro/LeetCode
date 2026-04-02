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
    TreeNode* recoverFromPreorder(string traversal) {
        vector<TreeNode*> stack;
        int i = 0;
        while (i < traversal.size()) {
            int depth = 0;
            while (i < traversal.size() && traversal[i] == '-') { depth++; i++; }
            int val = 0;
            while (i < traversal.size() && isdigit(traversal[i]))
                val = val * 10 + (traversal[i++] - '0');
            TreeNode* node = new TreeNode(val);
            while (stack.size() > depth) stack.pop_back();
            if (!stack.empty()) {
                if (!stack.back()->left) stack.back()->left = node;
                else stack.back()->right = node;
            }
            stack.push_back(node);
        }
        return stack[0];
    }
};
