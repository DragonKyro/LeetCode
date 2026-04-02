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
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_set<int> children;
        for (int l : leftChild) if (l != -1) children.insert(l);
        for (int r : rightChild) if (r != -1) children.insert(r);
        int root = -1;
        for (int i = 0; i < n; i++) if (!children.count(i)) { if (root != -1) return false; root = i; }
        if (root == -1) return false;
        unordered_set<int> visited;
        stack<int> st;
        st.push(root);
        while (!st.empty()) {
            int node = st.top(); st.pop();
            if (visited.count(node)) return false;
            visited.insert(node);
            if (leftChild[node] != -1) st.push(leftChild[node]);
            if (rightChild[node] != -1) st.push(rightChild[node]);
        }
        return (int)visited.size() == n;
    }
};
