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
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        long long windowSum = 0, result = 0;
        for (int i = 0; i < nums.size(); i++) {
            windowSum += nums[i];
            count[nums[i]]++;
            if (i >= k) {
                windowSum -= nums[i - k];
                if (--count[nums[i - k]] == 0) count.erase(nums[i - k]);
            }
            if (i >= k - 1 && (int)count.size() == k) result = max(result, windowSum);
        }
        return result;
    }
};
