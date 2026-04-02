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
    int neitherMinNorMax(vector<int>& nums) {
        if (nums.size() < 3) return -1;
        vector<int> a = {nums[0], nums[1], nums[2]};
        sort(a.begin(), a.end());
        return a[1];
    }
};
