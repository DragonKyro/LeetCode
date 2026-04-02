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
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        auto count = [&](long long x) {
            long long total = 0;
            for (int mask = 1; mask < (1 << n); mask++) {
                long long lcm = 1;
                int bits = 0;
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        lcm = lcm / __gcd(lcm, (long long)coins[i]) * coins[i];
                        bits++;
                        if (lcm > x) break;
                    }
                }
                if (bits % 2 == 1) total += x / lcm;
                else total -= x / lcm;
            }
            return total;
        };
        long long lo = 1, hi = (long long)*min_element(coins.begin(),coins.end()) * k;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (count(mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
