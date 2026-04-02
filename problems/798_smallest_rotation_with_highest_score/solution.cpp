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
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> change(n, 0);
        for (int i = 0; i < n; i++) {
            int lo = (i + 1) % n;
            int hi = (i - nums[i] + n) % n;
            if (lo <= hi) {
                change[lo]++;
                if (hi + 1 < n) change[hi + 1]--;
            } else {
                change[0]++;
                if (hi + 1 < n) change[hi + 1]--;
                change[lo]++;
            }
        }
        int best = -1, bestK = 0, cur = 0;
        for (int k = 0; k < n; k++) {
            cur += change[k];
            if (cur > best) { best = cur; bestK = k; }
        }
        return bestK;
    }
};
