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
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
        });
        int count = 0, maxEnd = 0;
        for (auto& iv : intervals) {
            if (iv[1] > maxEnd) { count++; maxEnd = iv[1]; }
        }
        return count;
    }
};
