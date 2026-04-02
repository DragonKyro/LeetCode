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
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](auto& a, auto& b) {
            return (a[0] - a[1]) < (b[0] - b[1]);
        });
        int n = costs.size() / 2, total = 0;
        for (int i = 0; i < n; i++)
            total += costs[i][0] + costs[i + n][1];
        return total;
    }
};
