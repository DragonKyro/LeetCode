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
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        function<void()> bt = [&]() {
            if (path.size() == nums.size()) { res.push_back(path); return; }
            for (int i = 0; i < nums.size(); i++) {
                if (used[i]) continue;
                used[i] = true;
                path.push_back(nums[i]);
                bt();
                path.pop_back();
                used[i] = false;
            }
        };
        bt();
        return res;
    }
};
