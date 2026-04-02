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
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int j = 0;
        map<int,int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            while (mp.rbegin()->first - mp.begin()->first > 2) {
                if (--mp[nums[j]] == 0) mp.erase(nums[j]);
                j++;
            }
            ans += i - j + 1;
        }
        return ans;
    }
};
