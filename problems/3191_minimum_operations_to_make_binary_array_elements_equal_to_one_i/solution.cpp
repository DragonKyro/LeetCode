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
    int minOperations(vector<int>& nums) {
        int n = nums.size(), ops = 0;
        for (int i = 0; i <= n-3; i++) {
            if (nums[i] == 0) {
                nums[i]^=1; nums[i+1]^=1; nums[i+2]^=1;
                ops++;
            }
        }
        return nums[n-1]==1 && nums[n-2]==1 ? ops : -1;
    }
};
