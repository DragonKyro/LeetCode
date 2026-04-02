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
    long long maxStrength(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> neg, pos;
        for (int n : nums) { if (n < 0) neg.push_back(n); else if (n > 0) pos.push_back(n); }
        sort(neg.begin(), neg.end());
        if (neg.size() % 2 == 1) neg.pop_back();
        if (neg.empty() && pos.empty()) return 0;
        long long res = 1;
        for (int n : neg) res *= n;
        for (int n : pos) res *= n;
        return res;
    }
};
