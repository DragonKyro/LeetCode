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
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        vector<int> result(n);
        int prefix = 0;
        for (int i = 0; i < n; i++) {
            int leftSum = prefix;
            int rightSum = total - prefix - nums[i];
            result[i] = nums[i] * i - leftSum + rightSum - nums[i] * (n - i - 1);
            prefix += nums[i];
        }
        return result;
    }
};
