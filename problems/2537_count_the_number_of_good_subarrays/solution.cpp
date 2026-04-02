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
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        long long pairs = 0, ans = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            pairs += cnt[nums[i]];
            cnt[nums[i]]++;
            while (pairs >= k) { cnt[nums[j]]--; pairs -= cnt[nums[j]]; j++; }
            ans += j;
        }
        return ans;
    }
};
