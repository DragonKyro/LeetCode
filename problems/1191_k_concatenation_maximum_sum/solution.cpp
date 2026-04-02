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
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long MOD = 1e9 + 7;
        long long total = accumulate(arr.begin(), arr.end(), 0LL);
        auto kadane = [](vector<int>& a, int rep) {
            long long maxSum = 0, curr = 0;
            for (int t = 0; t < rep; t++)
                for (int x : a) {
                    curr = max(0LL, curr + x);
                    maxSum = max(maxSum, curr);
                }
            return maxSum;
        };
        if (k == 1) return kadane(arr, 1) % MOD;
        long long twoMax = kadane(arr, 2);
        if (total > 0) return (twoMax + (k - 2) * total % MOD) % MOD;
        return twoMax % MOD;
    }
};
