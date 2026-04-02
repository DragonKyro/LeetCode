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
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> seen;
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            if (!seen.insert(nums[i] + nums[i+1]).second) return true;
        }
        return false;
    }
};
