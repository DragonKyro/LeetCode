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
    int dominantIndex(vector<int>& nums) {
        int maxIdx = max_element(nums.begin(), nums.end()) - nums.begin();
        for (int i = 0; i < (int)nums.size(); i++)
            if (i != maxIdx && nums[maxIdx] < 2 * nums[i]) return -1;
        return maxIdx;
    }
};
