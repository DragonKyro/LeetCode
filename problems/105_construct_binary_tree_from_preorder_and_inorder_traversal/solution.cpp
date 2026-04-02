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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) inorderMap[inorder[i]] = i;
        int preIdx = 0;
        return helper(preorder, inorderMap, preIdx, 0, inorder.size() - 1);
    }
    TreeNode* helper(vector<int>& preorder, unordered_map<int, int>& inorderMap, int& preIdx, int left, int right) {
        if (left > right) return nullptr;
        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = inorderMap[rootVal];
        root->left = helper(preorder, inorderMap, preIdx, left, mid - 1);
        root->right = helper(preorder, inorderMap, preIdx, mid + 1, right);
        return root;
    }
};
