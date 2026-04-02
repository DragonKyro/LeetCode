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
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long result = 0;
        int lastMin = -1, lastMax = -1, lastBad = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) lastBad = i;
            if (nums[i] == minK) lastMin = i;
            if (nums[i] == maxK) lastMax = i;
            result += max(0, min(lastMin, lastMax) - lastBad);
        }
        return result;
    }
};
