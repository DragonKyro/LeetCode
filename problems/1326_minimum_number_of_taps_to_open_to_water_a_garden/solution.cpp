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
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxReach(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            maxReach[left] = max(maxReach[left], right);
        }
        int taps = 0, curEnd = 0, far = 0;
        for (int i = 0; i < n; i++) {
            far = max(far, maxReach[i]);
            if (i == curEnd) {
                if (far <= curEnd) return -1;
                taps++; curEnd = far;
            }
        }
        return taps;
    }
};
