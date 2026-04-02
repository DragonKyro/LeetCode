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
    vector<int> smallestRange(vector<vector<int>>& nums) {
        auto cmp = [](auto& a, auto& b) { return a[0] > b[0]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        int maxVal = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], i, 0});
            maxVal = max(maxVal, nums[i][0]);
        }
        vector<int> best = {0, INT_MAX};
        while (true) {
            auto curr = pq.top(); pq.pop();
            int minVal = curr[0], i = curr[1], j = curr[2];
            if (maxVal - minVal < best[1] - best[0]) best = {minVal, maxVal};
            if (j + 1 >= (int)nums[i].size()) break;
            int next = nums[i][j + 1];
            maxVal = max(maxVal, next);
            pq.push({next, i, j + 1});
        }
        return best;
    }
};
