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
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int MOD = 1e9 + 7;
        vector<int> sums;
        for (int i = 0; i < n; i++) {
            int s = 0;
            for (int j = i; j < n; j++) {
                s += nums[j];
                sums.push_back(s);
            }
        }
        sort(sums.begin(), sums.end());
        long long res = 0;
        for (int i = left - 1; i < right; i++) res = (res + sums[i]) % MOD;
        return res;
    }
};
