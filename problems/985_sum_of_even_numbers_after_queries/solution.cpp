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
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evenSum = 0;
        for (int n : nums) if (n % 2 == 0) evenSum += n;
        vector<int> result;
        for (auto& q : queries) {
            int val = q[0], idx = q[1];
            if (nums[idx] % 2 == 0) evenSum -= nums[idx];
            nums[idx] += val;
            if (nums[idx] % 2 == 0) evenSum += nums[idx];
            result.push_back(evenSum);
        }
        return result;
    }
};
