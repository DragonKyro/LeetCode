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
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int t = 0; t < k; t++) {
            int idx = min_element(nums.begin(), nums.end()) - nums.begin();
            nums[idx] *= multiplier;
        }
        return nums;
    }
};
