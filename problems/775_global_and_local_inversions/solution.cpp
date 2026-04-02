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
    bool isIdealPermutation(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size(); i++)
            if (abs(nums[i] - i) > 1) return false;
        return true;
    }
};
