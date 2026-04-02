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
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i = 0, j = 1, n = nums.size();
        while (i < n && j < n) {
            if (nums[i] % 2 == 0) i += 2;
            else if (nums[j] % 2 == 1) j += 2;
            else { swap(nums[i], nums[j]); i += 2; j += 2; }
        }
        return nums;
    }
};
