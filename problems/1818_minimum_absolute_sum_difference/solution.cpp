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
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        long long MOD = 1e9 + 7;
        int n = nums1.size();
        vector<int> sorted1(nums1);
        sort(sorted1.begin(), sorted1.end());
        long long total = 0;
        for (int i = 0; i < n; i++) total += abs(nums1[i] - nums2[i]);
        long long maxImprove = 0;
        for (int i = 0; i < n; i++) {
            int curr = abs(nums1[i] - nums2[i]);
            auto it = lower_bound(sorted1.begin(), sorted1.end(), nums2[i]);
            if (it != sorted1.end()) maxImprove = max(maxImprove, (long long)(curr - abs(*it - nums2[i])));
            if (it != sorted1.begin()) { --it; maxImprove = max(maxImprove, (long long)(curr - abs(*it - nums2[i]))); }
        }
        return (total - maxImprove) % MOD;
    }
};
