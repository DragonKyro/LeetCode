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
    int splitArray(vector<int>& nums, int k) {
        long left = *max_element(nums.begin(), nums.end());
        long right = accumulate(nums.begin(), nums.end(), 0L);
        while (left < right) {
            long mid = left + (right - left) / 2;
            int pieces = 1;
            long sum = 0;
            for (int num : nums) {
                if (sum + num > mid) {
                    pieces++;
                    sum = num;
                } else {
                    sum += num;
                }
            }
            if (pieces <= k) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
