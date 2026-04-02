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
    unordered_set<int> seen;
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        if (seen.count(k - root->val)) return true;
        seen.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
