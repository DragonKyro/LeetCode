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
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int n : nums) mp[n]++;
        int res = 0;
        for (auto& [k, v] : mp)
            if (mp.count(k + 1))
                res = max(res, v + mp[k + 1]);
        return res;
    }
};
