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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
    TreeNode* build(vector<int>& nums, int lo, int hi) {
        if (lo > hi) return nullptr;
        int maxIdx = lo;
        for (int i = lo + 1; i <= hi; i++) {
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }
        TreeNode* root = new TreeNode(nums[maxIdx]);
        root->left = build(nums, lo, maxIdx - 1);
        root->right = build(nums, maxIdx + 1, hi);
        return root;
    }
};
