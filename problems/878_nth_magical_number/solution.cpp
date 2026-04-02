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
    int nthMagicalNumber(int n, int a, int b) {
        long MOD = 1e9 + 7;
        long lcm = (long)a / __gcd(a, b) * b;
        long lo = 1, hi = (long)n * min(a, b);
        while (lo < hi) {
            long mid = (lo + hi) / 2;
            if (mid / a + mid / b - mid / lcm >= n) hi = mid;
            else lo = mid + 1;
        }
        return lo % MOD;
    }
};
