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
    int minCapability(vector<int>& nums, int k) {
        int lo = *min_element(nums.begin(), nums.end()), hi = *max_element(nums.begin(), nums.end());
        while (lo < hi) {
            int mid = (lo+hi)/2, count = 0;
            for (int i = 0; i < nums.size(); ) { if (nums[i] <= mid) { count++; i += 2; } else i++; }
            if (count >= k) hi = mid; else lo = mid+1;
        }
        return lo;
    }
};
