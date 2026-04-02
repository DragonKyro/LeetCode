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
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        auto countLess = [&](int target) {
            long long cnt = 0; int lo = 0, hi = nums.size()-1;
            while (lo < hi) { if (nums[lo]+nums[hi] <= target) { cnt += hi-lo; lo++; } else hi--; }
            return cnt;
        };
        return countLess(upper) - countLess(lower - 1);
    }
};
