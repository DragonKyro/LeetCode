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
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size(), d = to_string(nums[0]).size();
        long long res = 0;
        for (int pos = 0; pos < d; pos++) {
            int cnt[10] = {};
            int pw = 1;
            for (int k = 0; k < pos; k++) pw *= 10;
            for (int x : nums) cnt[(x/pw)%10]++;
            for (int c : cnt) res += (long long)c * (n - c);
        }
        return res / 2;
    }
};
