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
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 1;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]+1) cnt++;
            else cnt = 1;
            if (i >= k-1) res.push_back(cnt >= k ? nums[i] : -1);
        }
        return res;
    }
};
