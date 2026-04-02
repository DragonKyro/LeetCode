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
    long long subArrayRanges(vector<int>& nums) {
        long long result = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int minVal = nums[i], maxVal = nums[i];
            for (int j = i + 1; j < n; j++) {
                minVal = min(minVal, nums[j]);
                maxVal = max(maxVal, nums[j]);
                result += maxVal - minVal;
            }
        }
        return result;
    }
};
