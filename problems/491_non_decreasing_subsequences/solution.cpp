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
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(nums, 0, path, result);
        return result;
    }
    void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& result) {
        if (path.size() >= 2) result.push_back(path);
        unordered_set<int> used;
        for (int i = start; i < nums.size(); i++) {
            if (used.count(nums[i])) continue;
            if (path.empty() || nums[i] >= path.back()) {
                used.insert(nums[i]);
                path.push_back(nums[i]);
                backtrack(nums, i + 1, path, result);
                path.pop_back();
            }
        }
    }
};
