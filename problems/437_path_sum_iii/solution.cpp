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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> prefix;
        prefix[0] = 1;
        return dfs(root, 0L, targetSum, prefix);
    }
    int dfs(TreeNode* node, long currSum, int target, unordered_map<long, int>& prefix) {
        if (!node) return 0;
        currSum += node->val;
        int count = prefix[currSum - target];
        prefix[currSum]++;
        count += dfs(node->left, currSum, target, prefix);
        count += dfs(node->right, currSum, target, prefix);
        prefix[currSum]--;
        return count;
    }
};
