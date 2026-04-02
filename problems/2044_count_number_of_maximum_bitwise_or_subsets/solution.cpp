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
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int num : nums) maxOr |= num;
        int count = 0, n = nums.size();
        for (int mask = 1; mask < (1 << n); mask++) {
            int cur = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) cur |= nums[i];
            }
            if (cur == maxOr) count++;
        }
        return count;
    }
};
