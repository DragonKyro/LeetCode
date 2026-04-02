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
    int maxLength(vector<string>& arr) {
        vector<int> dp = {0};
        int res = 0;
        for (auto& s : arr) {
            int mask = 0; bool dup = false;
            for (char c : s) {
                int bit = 1 << (c - 'a');
                if (mask & bit) { dup = true; break; }
                mask |= bit;
            }
            if (dup) continue;
            vector<int> newDp;
            for (int existing : dp) {
                if (existing & mask) continue;
                int combined = existing | mask;
                newDp.push_back(combined);
                res = max(res, __builtin_popcount(combined));
            }
            dp.insert(dp.end(), newDp.begin(), newDp.end());
        }
        return res;
    }
};
