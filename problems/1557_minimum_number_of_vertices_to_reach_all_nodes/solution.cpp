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
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> hasIncoming(n, false);
        for (auto& e : edges) hasIncoming[e[1]] = true;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (!hasIncoming[i]) res.push_back(i);
        }
        return res;
    }
};
