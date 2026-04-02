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
    int beautifulSubsets(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int,int> used;
        function<void(int)> bt = [&](int idx) {
            if (idx == nums.size()) { if (!used.empty()) count++; return; }
            bt(idx+1);
            if (used[nums[idx]-k]==0 && used[nums[idx]+k]==0) {
                used[nums[idx]]++;
                bt(idx+1);
                if (--used[nums[idx]] == 0) used.erase(nums[idx]);
            }
        };
        bt(0);
        return count;
    }
};
