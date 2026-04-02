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
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int lo = *min_element(nums.begin(), nums.end());
        int hi = *max_element(nums.begin(), nums.end());
        if (lo == hi) return 0;
        int n = nums.size();
        int bucketSize = max(1, (hi - lo) / (n - 1));
        int bucketCount = (hi - lo) / bucketSize + 1;
        vector<int> bMin(bucketCount, INT_MAX), bMax(bucketCount, INT_MIN);
        for (int num : nums) {
            int idx = (num - lo) / bucketSize;
            bMin[idx] = min(bMin[idx], num);
            bMax[idx] = max(bMax[idx], num);
        }
        int res = 0, prevMax = bMax[0];
        for (int i = 1; i < bucketCount; i++) {
            if (bMin[i] == INT_MAX) continue;
            res = max(res, bMin[i] - prevMax);
            prevMax = bMax[i];
        }
        return res;
    }
};
