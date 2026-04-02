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
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> all(nums.begin(), nums.end());
        int total = all.size(), n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            set<int> s;
            for (int j = i; j < n; j++) {
                s.insert(nums[j]);
                if ((int)s.size() == total) { ans += n - j; break; }
            }
        }
        return ans;
    }
};
