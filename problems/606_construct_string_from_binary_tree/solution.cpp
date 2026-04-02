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
    string tree2str(TreeNode* root) {
        if (!root) return "";
        string result = to_string(root->val);
        if (root->left || root->right) {
            result += "(" + tree2str(root->left) + ")";
        }
        if (root->right) {
            result += "(" + tree2str(root->right) + ")";
        }
        return result;
    }
};
