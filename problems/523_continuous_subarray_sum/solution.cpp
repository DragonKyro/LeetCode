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
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int running = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            running += nums[i];
            int mod = running % k;
            if (mp.count(mod)) {
                if (i - mp[mod] >= 2) return true;
            } else {
                mp[mod] = i;
            }
        }
        return false;
    }
};
