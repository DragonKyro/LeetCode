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
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int n : nums) mp[n]++;
        int res = 0;
        for (auto& [key, cnt] : mp) {
            if (k == 0 && cnt > 1) res++;
            else if (k > 0 && mp.count(key + k)) res++;
        }
        return res;
    }
};
