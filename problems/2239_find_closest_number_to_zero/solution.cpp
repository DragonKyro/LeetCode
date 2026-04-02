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
    int findClosestNumber(vector<int>& nums) {
        int res = nums[0];
        for (int n : nums) {
            if (abs(n) < abs(res) || (abs(n) == abs(res) && n > res)) {
                res = n;
            }
        }
        return res;
    }
};
