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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int num : nums) {
            int idx = abs(num) - 1;
            if (nums[idx] > 0) nums[idx] = -nums[idx];
        }
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) result.push_back(i + 1);
        }
        return result;
    }
};
