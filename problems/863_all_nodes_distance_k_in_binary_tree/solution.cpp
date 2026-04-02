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
    unordered_map<TreeNode*, TreeNode*> parent;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, nullptr);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target); visited.insert(target);
        int dist = 0;
        while (!q.empty()) {
            if (dist == k) {
                vector<int> res;
                while (!q.empty()) { res.push_back(q.front()->val); q.pop(); }
                return res;
            }
            int sz = q.size();
            while (sz--) {
                auto node = q.front(); q.pop();
                for (auto nei : {node->left, node->right, parent[node]}) {
                    if (nei && !visited.count(nei)) { visited.insert(nei); q.push(nei); }
                }
            }
            dist++;
        }
        return {};
    }
    void dfs(TreeNode* node, TreeNode* par) {
        if (!node) return;
        parent[node] = par;
        dfs(node->left, node); dfs(node->right, node);
    }
};
