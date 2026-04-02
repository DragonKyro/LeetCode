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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) inorderMap[inorder[i]] = i;
        int postIdx = postorder.size() - 1;
        return helper(postorder, inorderMap, postIdx, 0, inorder.size() - 1);
    }
    TreeNode* helper(vector<int>& postorder, unordered_map<int, int>& inorderMap, int& postIdx, int left, int right) {
        if (left > right) return nullptr;
        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);
        int mid = inorderMap[rootVal];
        root->right = helper(postorder, inorderMap, postIdx, mid + 1, right);
        root->left = helper(postorder, inorderMap, postIdx, left, mid - 1);
        return root;
    }
};
