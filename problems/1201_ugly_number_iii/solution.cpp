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
    int nthUglyNumber(int n, int a, int b, int c) {
        long long ab = lcm((long long)a, (long long)b);
        long long ac = lcm((long long)a, (long long)c);
        long long bc = lcm((long long)b, (long long)c);
        long long abc = lcm(ab, (long long)c);
        long long lo = 1, hi = 2e9;
        while (lo < hi) {
            long long mid = (lo + hi) / 2;
            long long cnt = mid/a + mid/b + mid/c - mid/ab - mid/ac - mid/bc + mid/abc;
            if (cnt < n) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
    long long gcd(long long x, long long y) { return y == 0 ? x : gcd(y, x % y); }
    long long lcm(long long x, long long y) { return x / gcd(x, y) * y; }
};
