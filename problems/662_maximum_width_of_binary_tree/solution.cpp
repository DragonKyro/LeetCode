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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int maxWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            unsigned long long first = q.front().second;
            unsigned long long last = first;
            for (int i = 0; i < size; i++) {
                auto [node, idx] = q.front(); q.pop();
                last = idx;
                if (node->left) q.push({node->left, 2 * idx});
                if (node->right) q.push({node->right, 2 * idx + 1});
            }
            maxWidth = max(maxWidth, (int)(last - first + 1));
        }
        return maxWidth;
    }
};
