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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> graph;
        function<void(TreeNode*, TreeNode*)> build = [&](TreeNode* node, TreeNode* parent) {
            if (!node) return;
            if (parent) {
                graph[node->val].push_back(parent->val);
                graph[parent->val].push_back(node->val);
            }
            build(node->left, node); build(node->right, node);
        };
        build(root, nullptr);
        unordered_set<int> visited = {start};
        queue<int> q;
        q.push(start);
        int time = -1;
        while (!q.empty()) {
            time++;
            int sz = q.size();
            while (sz--) {
                int node = q.front(); q.pop();
                for (int nb : graph[node]) {
                    if (!visited.count(nb)) { visited.insert(nb); q.push(nb); }
                }
            }
        }
        return time;
    }
};
