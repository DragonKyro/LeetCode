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
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> first, last, count;
        for (int i = 0; i < nums.size(); i++) {
            if (!first.count(nums[i])) first[nums[i]] = i;
            last[nums[i]] = i;
            count[nums[i]]++;
        }
        int degree = 0;
        for (auto& [k, v] : count) degree = max(degree, v);
        int result = nums.size();
        for (auto& [k, v] : count) {
            if (v == degree) result = min(result, last[k] - first[k] + 1);
        }
        return result;
    }
};
