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
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for (int n : nums) cnt[n]++;
        int dom = 0, maxCnt = 0;
        for (auto& [k,v] : cnt) if (v > maxCnt) { dom = k; maxCnt = v; }
        int left = 0, n = nums.size();
        for (int i = 0; i < n-1; i++) {
            if (nums[i] == dom) left++;
            if (left*2 > i+1 && (maxCnt-left)*2 > n-i-1) return i;
        }
        return -1;
    }
};
