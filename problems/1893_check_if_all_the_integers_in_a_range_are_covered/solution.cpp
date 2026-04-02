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
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for (int i = left; i <= right; i++) {
            bool covered = false;
            for (auto& r : ranges) {
                if (r[0] <= i && i <= r[1]) { covered = true; break; }
            }
            if (!covered) return false;
        }
        return true;
    }
};
