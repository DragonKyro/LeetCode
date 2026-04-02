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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sums;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            long long s = 0; int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto n = q.front(); q.pop(); s += n->val;
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            sums.push_back(s);
        }
        if (k > sums.size()) return -1;
        sort(sums.rbegin(), sums.rend());
        return sums[k-1];
    }
};
