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
    int maxDepth(Node* root) {
        if (!root) return 0;
        int mx = 0;
        for (auto child : root->children)
            mx = max(mx, maxDepth(child));
        return 1 + mx;
    }
};
