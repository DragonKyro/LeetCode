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
    unordered_map<string, int> count;
    vector<TreeNode*> result;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return result;
    }
    string serialize(TreeNode* node) {
        if (!node) return "#";
        string s = to_string(node->val) + "," + serialize(node->left) + "," + serialize(node->right);
        if (++count[s] == 2) result.push_back(node);
        return s;
    }
};
