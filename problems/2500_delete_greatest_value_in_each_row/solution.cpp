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
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (auto& row : grid) sort(row.begin(), row.end());
        int result = 0;
        for (int j = 0; j < grid[0].size(); j++) {
            int mx = 0;
            for (auto& row : grid) mx = max(mx, row[j]);
            result += mx;
        }
        return result;
    }
};
