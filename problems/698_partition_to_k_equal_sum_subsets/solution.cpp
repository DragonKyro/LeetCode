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
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        int target = sum / k;
        sort(nums.rbegin(), nums.rend());
        if (nums[0] > target) return false;
        vector<int> buckets(k, 0);
        function<bool(int)> backtrack = [&](int idx) -> bool {
            if (idx == nums.size()) return true;
            for (int i = 0; i < k; i++) {
                if (buckets[i] + nums[idx] <= target) {
                    buckets[i] += nums[idx];
                    if (backtrack(idx + 1)) return true;
                    buckets[i] -= nums[idx];
                }
                if (buckets[i] == 0) break;
            }
            return false;
        };
        return backtrack(0);
    }
};
