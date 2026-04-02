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
    int minimizeSet(int d1, int d2, int cnt1, int cnt2) {
        long long lcm = (long long) d1 / __gcd(d1, d2) * d2;
        long long lo = 1, hi = 2e9;
        while (lo < hi) {
            long long mid = (lo + hi) / 2;
            long long a = mid - mid/d1, b = mid - mid/d2, c = mid - mid/lcm;
            if (a >= cnt1 && b >= cnt2 && c >= cnt1+cnt2) hi = mid; else lo = mid+1;
        }
        return lo;
    }
};
