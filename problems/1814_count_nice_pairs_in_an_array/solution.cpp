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
    int countNicePairs(vector<int>& nums) {
        long long MOD = 1e9 + 7;
        unordered_map<int, int> mp;
        long long result = 0;
        for (int x : nums) {
            int diff = x - rev(x);
            result = (result + mp[diff]) % MOD;
            mp[diff]++;
        }
        return result;
    }
    int rev(int x) {
        int r = 0;
        while (x > 0) { r = r * 10 + x % 10; x /= 10; }
        return r;
    }
};
