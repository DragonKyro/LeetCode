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
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int> cnt(201, 0);
        for (int x : nums) { if (x > n) return false; cnt[x]++; }
        for (int i = 1; i < n; i++) if (cnt[i] != 1) return false;
        return cnt[n] == 2;
    }
};
