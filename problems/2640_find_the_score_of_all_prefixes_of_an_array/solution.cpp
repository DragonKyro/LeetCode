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
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans;
        long long mx = 0, s = 0;
        for (int n : nums) { mx = max(mx, (long long)n); s += n + mx; ans.push_back(s); }
        return ans;
    }
};
