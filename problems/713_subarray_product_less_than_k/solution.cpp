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
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int prod = 1, left = 0, count = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            prod *= nums[right];
            while (prod >= k) prod /= nums[left++];
            count += right - left + 1;
        }
        return count;
    }
};
