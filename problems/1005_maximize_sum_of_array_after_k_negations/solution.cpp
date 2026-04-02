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
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        while (k > 0 && i < nums.size() && nums[i] < 0) {
            nums[i] = -nums[i];
            i++;
            k--;
        }
        if (k % 2 == 1) {
            sort(nums.begin(), nums.end());
            nums[0] = -nums[0];
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};
