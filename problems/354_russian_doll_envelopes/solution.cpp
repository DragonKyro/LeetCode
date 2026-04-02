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
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](auto& a, auto& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        vector<int> dp;
        for (auto& e : envelopes) {
            auto it = lower_bound(dp.begin(), dp.end(), e[1]);
            if (it == dp.end()) dp.push_back(e[1]);
            else *it = e[1];
        }
        return dp.size();
    }
};
