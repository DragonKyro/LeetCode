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
    long long maxArrayValue(vector<int>& nums) {
        long long cur = nums.back();
        for (int i = nums.size()-2; i >= 0; i--) {
            if (nums[i] <= cur) cur += nums[i];
            else cur = nums[i];
        }
        return cur;
    }
};
