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
    int maxValue(int n, int index, int maxSum) {
        auto count = [&](long long mid) -> long long {
            long long total = mid;
            long long left = min(mid - 1, (long long)index);
            long long right = min(mid - 1, (long long)(n - 1 - index));
            total += left * (left + 1) / 2;
            if (left < index) total += index - left;
            else total -= (left - index) * (left - index + 1) / 2;
            total += right * (right + 1) / 2;
            if (right < n - 1 - index) total += n - 1 - index - right;
            else total -= (right - (n - 1 - index)) * (right - (n - 1 - index) + 1) / 2;
            return total;
        };
        int lo = 1, hi = maxSum;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (count(mid) <= maxSum) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};
