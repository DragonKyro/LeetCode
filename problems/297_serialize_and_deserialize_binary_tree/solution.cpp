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

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "null";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return helper(ss);
    }

    TreeNode* helper(istringstream& ss) {
        string val;
        getline(ss, val, ',');
        if (val == "null") return nullptr;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = helper(ss);
        node->right = helper(ss);
        return node;
    }
};
