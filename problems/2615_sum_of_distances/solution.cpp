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
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < nums.size(); i++) groups[nums[i]].push_back(i);
        vector<long long> ans(nums.size());
        for (auto& [_, indices] : groups) {
            int m = indices.size();
            vector<long long> pre(m+1, 0);
            for (int i = 0; i < m; i++) pre[i+1] = pre[i] + indices[i];
            for (int i = 0; i < m; i++) {
                long long left = (long long)indices[i]*i - pre[i];
                long long right = (pre[m]-pre[i+1]) - (long long)indices[i]*(m-i-1);
                ans[indices[i]] = left + right;
            }
        }
        return ans;
    }
};
