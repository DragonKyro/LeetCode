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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generate(1, n);
    }

    vector<TreeNode*> generate(int start, int end) {
        if (start > end) return {nullptr};
        vector<TreeNode*> trees;
        for (int i = start; i <= end; i++) {
            auto leftTrees = generate(start, i - 1);
            auto rightTrees = generate(i + 1, end);
            for (auto l : leftTrees) {
                for (auto r : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }
};
