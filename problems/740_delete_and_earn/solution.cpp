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
    int deleteAndEarn(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> points(mx + 1, 0);
        for (int n : nums) points[n] += n;
        int take = 0, skip = 0;
        for (int i = 1; i <= mx; i++) {
            int newTake = skip + points[i];
            skip = max(take, skip);
            take = newTake;
        }
        return max(take, skip);
    }
};
