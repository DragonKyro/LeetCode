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
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for (int num : nums) {
            int idx = abs(num) - 1;
            if (nums[idx] < 0) result.push_back(abs(num));
            else nums[idx] = -nums[idx];
        }
        return result;
    }
};
