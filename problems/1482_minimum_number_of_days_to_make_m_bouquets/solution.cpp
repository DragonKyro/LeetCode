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
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > (int)bloomDay.size()) return -1;
        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int bouquets = 0, flowers = 0;
            for (int b : bloomDay) {
                if (b <= mid) { flowers++; if (flowers == k) { bouquets++; flowers = 0; } }
                else flowers = 0;
            }
            if (bouquets >= m) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
