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
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> edgeCount;
        for (auto& row : wall) {
            int pos = 0;
            for (int i = 0; i < (int)row.size() - 1; i++) {
                pos += row[i];
                edgeCount[pos]++;
            }
        }
        int maxEdges = 0;
        for (auto& [k, v] : edgeCount) maxEdges = max(maxEdges, v);
        return wall.size() - maxEdges;
    }
};
