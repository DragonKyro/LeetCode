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
    bool canBeIncreasing(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            bool valid = true;
            int prev = -1;
            for (int j = 0; j < nums.size(); j++) {
                if (j == i) continue;
                if (nums[j] <= prev) { valid = false; break; }
                prev = nums[j];
            }
            if (valid) return true;
        }
        return false;
    }
};
