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
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        for (int x : nums) total += x;
        long long leftSum = 0, minDiff = LLONG_MAX;
        int result = 0;
        for (int i = 0; i < n; i++) {
            leftSum += nums[i];
            long long leftAvg = leftSum / (i + 1);
            long long rightAvg = i < n - 1 ? (total - leftSum) / (n - i - 1) : 0;
            long long diff = abs(leftAvg - rightAvg);
            if (diff < minDiff) { minDiff = diff; result = i; }
        }
        return result;
    }
};
