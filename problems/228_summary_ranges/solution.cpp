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
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int i = 0;
        while (i < nums.size()) {
            int start = nums[i];
            while (i + 1 < nums.size() && nums[i + 1] == nums[i] + 1) i++;
            if (start == nums[i]) res.push_back(to_string(start));
            else res.push_back(to_string(start) + "->" + to_string(nums[i]));
            i++;
        }
        return res;
    }
};
