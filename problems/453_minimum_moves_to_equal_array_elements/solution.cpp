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
    int minMoves(vector<int>& nums) {
        long sum = accumulate(nums.begin(), nums.end(), 0L);
        int minVal = *min_element(nums.begin(), nums.end());
        return sum - (long)minVal * nums.size();
    }
};
