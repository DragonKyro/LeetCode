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
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), maxSeen = INT_MIN, minSeen = INT_MAX;
        int end = -1, start = 0;
        for (int i = 0; i < n; i++) {
            maxSeen = max(maxSeen, nums[i]);
            if (nums[i] < maxSeen) end = i;
        }
        for (int i = n - 1; i >= 0; i--) {
            minSeen = min(minSeen, nums[i]);
            if (nums[i] > minSeen) start = i;
        }
        return end == -1 ? 0 : end - start + 1;
    }
};
