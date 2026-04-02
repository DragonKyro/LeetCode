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
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> indexed;
        for (int i = 0; i < (int)nums.size(); i++) indexed.push_back({nums[i], i});
        sort(indexed.rbegin(), indexed.rend());
        vector<pair<int, int>> top(indexed.begin(), indexed.begin() + k);
        sort(top.begin(), top.end(), [](auto& a, auto& b) { return a.second < b.second; });
        vector<int> result;
        for (auto& [val, idx] : top) result.push_back(val);
        return result;
    }
};
