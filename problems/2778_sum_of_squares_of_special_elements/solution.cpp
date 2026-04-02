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
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; i++) if (n % (i+1) == 0) sum += nums[i] * nums[i];
        return sum;
    }
};
