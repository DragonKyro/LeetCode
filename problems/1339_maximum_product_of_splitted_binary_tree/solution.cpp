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
    vector<long long> sums;
    long long totalSum(TreeNode* node) {
        if (!node) return 0;
        long long s = node->val + totalSum(node->left) + totalSum(node->right);
        sums.push_back(s);
        return s;
    }
    int maxProduct(TreeNode* root) {
        long long total = totalSum(root);
        long long res = 0;
        for (long long s : sums) res = max(res, s * (total - s));
        return res % 1000000007;
    }
};
