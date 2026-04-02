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
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minDist = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) minDist = min(minDist, abs(i - start));
        }
        return minDist;
    }
};
