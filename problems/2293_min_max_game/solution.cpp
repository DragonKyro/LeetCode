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
    int minMaxGame(vector<int>& nums) {
        while (nums.size() > 1) {
            vector<int> newNums;
            for (int i = 0; i < nums.size() / 2; i++) {
                newNums.push_back(i % 2 == 0 ? min(nums[2*i], nums[2*i+1]) : max(nums[2*i], nums[2*i+1]));
            }
            nums = newNums;
        }
        return nums[0];
    }
};
