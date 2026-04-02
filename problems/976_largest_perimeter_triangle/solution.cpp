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
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        for (int i = 0; i < nums.size() - 2; i++)
            if (nums[i] < nums[i + 1] + nums[i + 2])
                return nums[i] + nums[i + 1] + nums[i + 2];
        return 0;
    }
};
