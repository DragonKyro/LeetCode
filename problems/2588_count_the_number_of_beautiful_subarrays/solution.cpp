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
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int,int> cnt;
        cnt[0] = 1;
        int x = 0; long long ans = 0;
        for (int n : nums) { x ^= n; ans += cnt[x]; cnt[x]++; }
        return ans;
    }
};
