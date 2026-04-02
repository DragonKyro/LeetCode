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
    int preimageSizeFZF(int k) {
        return (int)(lowerBound(k + 1) - lowerBound(k));
    }

    long long lowerBound(int target) {
        long long lo = 0, hi = 5LL * (target + 1);
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countZeros(mid) < target) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }

    long long countZeros(long long n) {
        long long count = 0;
        for (long long d = 5; d <= n; d *= 5) count += n / d;
        return count;
    }
};
