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
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0, i = 0;
        for (int j = n/2; j < n && i < n/2; j++)
            if (2 * nums[i] <= nums[j]) { ans += 2; i++; }
        return ans;
    }
};
