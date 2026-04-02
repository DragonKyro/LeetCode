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
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i-1] + (nums[i]%2 == nums[i-1]%2);
        vector<bool> res;
        for (auto& q : queries)
            res.push_back(prefix[q[1]] - prefix[q[0]] == 0);
        return res;
    }
};
