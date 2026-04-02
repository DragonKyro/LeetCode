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
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<tuple<int,int,int>> intervals;
        vector<int> result;
        int maxHeight = 0;
        for (auto& pos : positions) {
            int left = pos[0], side = pos[1], right = left + side;
            int height = side;
            for (auto& [l, r, h] : intervals) {
                if (l < right && left < r) height = max(height, h + side);
            }
            intervals.emplace_back(left, right, height);
            maxHeight = max(maxHeight, height);
            result.push_back(maxHeight);
        }
        return result;
    }
};
