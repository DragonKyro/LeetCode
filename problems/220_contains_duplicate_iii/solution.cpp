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
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long> window;
        for (int i = 0; i < nums.size(); i++) {
            auto it = window.lower_bound((long)nums[i] - valueDiff);
            if (it != window.end() && *it <= (long)nums[i] + valueDiff) return true;
            window.insert(nums[i]);
            if (i >= indexDiff) window.erase(nums[i - indexDiff]);
        }
        return false;
    }
};
