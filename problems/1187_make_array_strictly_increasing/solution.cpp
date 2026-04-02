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
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        map<int, int> dp;
        dp[-1] = 0;
        for (int num : arr1) {
            map<int, int> newDp;
            for (auto& [prev, ops] : dp) {
                if (num > prev) {
                    if (!newDp.count(num) || newDp[num] > ops) newDp[num] = ops;
                }
                auto it = upper_bound(arr2.begin(), arr2.end(), prev);
                if (it != arr2.end()) {
                    int val = *it;
                    if (!newDp.count(val) || newDp[val] > ops + 1) newDp[val] = ops + 1;
                }
            }
            dp = newDp;
        }
        if (dp.empty()) return -1;
        int res = INT_MAX;
        for (auto& [k, v] : dp) res = min(res, v);
        return res;
    }
};
