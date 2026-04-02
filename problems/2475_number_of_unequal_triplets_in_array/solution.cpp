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
    int unequalTriplets(vector<int>& nums) {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                for (int k = j+1; k < n; k++)
                    if (nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k]) count++;
        return count;
    }
};
