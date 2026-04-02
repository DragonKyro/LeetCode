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
    int totalHammingDistance(vector<int>& nums) {
        int total = 0, n = nums.size();
        for (int bit = 0; bit < 32; bit++) {
            int ones = 0;
            for (int num : nums) if (num & (1 << bit)) ones++;
            total += ones * (n - ones);
        }
        return total;
    }
};
