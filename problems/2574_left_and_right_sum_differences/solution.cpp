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
    vector<int> leftRightDifference(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0), left = 0;
        vector<int> ans;
        for (int n : nums) { int right = total - left - n; ans.push_back(abs(left - right)); left += n; }
        return ans;
    }
};
