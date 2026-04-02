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
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (!root) return res;
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            auto node = st.top(); st.pop();
            res.push_back(node->val);
            for (int i = node->children.size() - 1; i >= 0; i--)
                st.push(node->children[i]);
        }
        return res;
    }
};
