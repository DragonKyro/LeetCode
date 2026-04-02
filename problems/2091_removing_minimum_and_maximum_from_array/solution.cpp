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
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIdx = max_element(nums.begin(), nums.end()) - nums.begin();
        int left = min(minIdx, maxIdx) + 1;
        int right = n - max(minIdx, maxIdx);
        int fromLeft = max(minIdx, maxIdx) + 1;
        int fromRight = n - min(minIdx, maxIdx);
        return min({left + right, fromLeft, fromRight});
    }
};
