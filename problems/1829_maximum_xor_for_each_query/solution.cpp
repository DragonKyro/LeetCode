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
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xorSum = 0;
        for (int x : nums) xorSum ^= x;
        int mask = (1 << maximumBit) - 1;
        vector<int> result;
        for (int i = nums.size() - 1; i >= 0; i--) {
            result.push_back(xorSum ^ mask);
            xorSum ^= nums[i];
        }
        return result;
    }
};
