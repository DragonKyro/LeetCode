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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> count;
        int maxFreq = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (!node) return 0;
            int s = node->val + dfs(node->left) + dfs(node->right);
            maxFreq = max(maxFreq, ++count[s]);
            return s;
        };
        dfs(root);
        vector<int> res;
        for (auto& [s, f] : count) if (f == maxFreq) res.push_back(s);
        return res;
    }
};
