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
    bool kLengthApart(vector<int>& nums, int k) {
        int last = -k - 1;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] == 1) {
                if (i - last - 1 < k) return false;
                last = i;
            }
        }
        return true;
    }
};
