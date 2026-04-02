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
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0, j = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i]-nums[j] > 2*k) j++;
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};
