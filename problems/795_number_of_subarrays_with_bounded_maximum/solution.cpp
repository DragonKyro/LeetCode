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
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return count(nums, right) - count(nums, left - 1);
    }

    int count(vector<int>& nums, int bound) {
        int ans = 0, cnt = 0;
        for (int num : nums) {
            cnt = num <= bound ? cnt + 1 : 0;
            ans += cnt;
        }
        return ans;
    }
};
