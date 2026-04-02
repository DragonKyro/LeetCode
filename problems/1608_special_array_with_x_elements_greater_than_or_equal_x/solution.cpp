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
    int specialArray(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        for (int x = 1; x <= n; x++) {
            if (nums[x - 1] >= x && (x == n || nums[x] < x)) {
                return x;
            }
        }
        return -1;
    }
};
