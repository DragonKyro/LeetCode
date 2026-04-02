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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int leftH = 0, rightH = 0;
        TreeNode* l = root;
        TreeNode* r = root;
        while (l) { leftH++; l = l->left; }
        while (r) { rightH++; r = r->right; }
        if (leftH == rightH) return (1 << leftH) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
