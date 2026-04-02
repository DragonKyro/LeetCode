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
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int lo = 0, hi = nums.back() - nums[0];
        while (lo < hi) {
            int mid = (lo+hi)/2, cnt = 0;
            for (int i = 1; i < nums.size(); i++) { if (nums[i]-nums[i-1] <= mid) { cnt++; i++; } }
            if (cnt >= p) hi = mid; else lo = mid+1;
        }
        return lo;
    }
};
