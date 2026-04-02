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
    int alternatingSubarray(vector<int>& nums) {
        int ans = -1, n = nums.size();
        for (int i = 0; i < n-1; i++) {
            if (nums[i+1]-nums[i] == 1) {
                int j = i+1, exp = -1;
                while (j+1<n && nums[j+1]-nums[j]==exp) { j++; exp *= -1; }
                ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};
