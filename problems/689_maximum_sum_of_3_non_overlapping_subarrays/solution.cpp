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
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums(n - k + 1);
        int s = 0;
        for (int i = 0; i < n; i++) {
            s += nums[i];
            if (i >= k) s -= nums[i - k];
            if (i >= k - 1) sums[i - k + 1] = s;
        }
        vector<int> left(sums.size()), right(sums.size());
        int best = 0;
        for (int i = 0; i < sums.size(); i++) {
            if (sums[i] > sums[best]) best = i;
            left[i] = best;
        }
        best = sums.size() - 1;
        for (int i = sums.size() - 1; i >= 0; i--) {
            if (sums[i] >= sums[best]) best = i;
            right[i] = best;
        }
        vector<int> result(3);
        int maxSum = 0;
        for (int j = k; j < (int)sums.size() - k; j++) {
            int li = left[j - k], ri = right[j + k];
            int total = sums[li] + sums[j] + sums[ri];
            if (total > maxSum) {
                maxSum = total;
                result = {li, j, ri};
            }
        }
        return result;
    }
};
