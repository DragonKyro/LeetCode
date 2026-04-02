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
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0, i = 0, n = nums.size();
        while (i < n) {
            if (nums[i]%2==0 && nums[i]<=threshold) {
                int j = i;
                while (j+1<n && nums[j+1]%2!=nums[j]%2 && nums[j+1]<=threshold) j++;
                ans = max(ans, j-i+1); i = j+1;
            } else i++;
        }
        return ans;
    }
};
