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
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int, int> count;
        for (auto& arr : nums)
            for (int x : arr) count[x]++;
        vector<int> res;
        for (auto& [k, v] : count)
            if (v == (int)nums.size()) res.push_back(k);
        return res;
    }
};
