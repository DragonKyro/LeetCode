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
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i+1]) { nums[i] *= 2; nums[i+1] = 0; }
        }
        vector<int> result;
        for (int num : nums) if (num != 0) result.push_back(num);
        result.resize(n, 0);
        return result;
    }
};
