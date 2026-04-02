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
    int arrayNesting(vector<int>& nums) {
        int maxLen = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] == -1) continue;
            int count = 0, j = i;
            while (nums[j] != -1) {
                int temp = nums[j];
                nums[j] = -1;
                j = temp;
                count++;
            }
            maxLen = max(maxLen, count);
        }
        return maxLen;
    }
};
