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
    int waysToSplitArray(vector<int>& nums) {
        long long total = 0;
        for (int n : nums) total += n;
        long long leftSum = 0;
        int count = 0;
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            leftSum += nums[i];
            if (leftSum >= total - leftSum) count++;
        }
        return count;
    }
};
