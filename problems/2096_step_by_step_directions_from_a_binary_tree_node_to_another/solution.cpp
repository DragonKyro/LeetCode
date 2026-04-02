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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathStart, pathDest;
        find(root, startValue, pathStart);
        find(root, destValue, pathDest);
        int i = 0;
        while (i < (int)pathStart.size() && i < (int)pathDest.size() && pathStart[i] == pathDest[i]) i++;
        return string(pathStart.size() - i, 'U') + pathDest.substr(i);
    }
    bool find(TreeNode* node, int target, string& path) {
        if (!node) return false;
        if (node->val == target) return true;
        path.push_back('L');
        if (find(node->left, target, path)) return true;
        path.pop_back();
        path.push_back('R');
        if (find(node->right, target, path)) return true;
        path.pop_back();
        return false;
    }
};
