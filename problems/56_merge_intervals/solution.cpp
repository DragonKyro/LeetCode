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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (auto& interval : intervals) {
            if (!merged.empty() && interval[0] <= merged.back()[1]) {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            } else {
                merged.push_back(interval);
            }
        }
        return merged;
    }
};
