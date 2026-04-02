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
    int movesToMakeZigzag(vector<int>& nums) {
        int result[2] = {0, 0};
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int left = i > 0 ? nums[i - 1] : INT_MAX;
            int right = i < n - 1 ? nums[i + 1] : INT_MAX;
            int diff = nums[i] - min(left, right) + 1;
            if (diff > 0) result[i % 2] += diff;
        }
        return min(result[0], result[1]);
    }
};
