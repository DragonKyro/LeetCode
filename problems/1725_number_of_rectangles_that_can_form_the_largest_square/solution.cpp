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
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxSide = 0, count = 0;
        for (auto& r : rectangles) {
            int side = min(r[0], r[1]);
            if (side > maxSide) { maxSide = side; count = 1; }
            else if (side == maxSide) count++;
        }
        return count;
    }
};
