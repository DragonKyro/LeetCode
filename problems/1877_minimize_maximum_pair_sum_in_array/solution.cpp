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
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), result = 0;
        for (int i = 0; i < n / 2; i++) {
            result = max(result, nums[i] + nums[n - 1 - i]);
        }
        return result;
    }
};
