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
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int maxLen = 0, count = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            count += nums[i] == 1 ? 1 : -1;
            if (mp.count(count)) maxLen = max(maxLen, i - mp[count]);
            else mp[count] = i;
        }
        return maxLen;
    }
};
