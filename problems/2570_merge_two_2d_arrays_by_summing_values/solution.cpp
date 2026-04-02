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
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> m;
        for (auto& n : nums1) m[n[0]] += n[1];
        for (auto& n : nums2) m[n[0]] += n[1];
        vector<vector<int>> res;
        for (auto& [k,v] : m) res.push_back({k, v});
        return res;
    }
};
