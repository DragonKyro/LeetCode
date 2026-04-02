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
    int matrixSum(vector<vector<int>>& nums) {
        for (auto& row : nums) sort(row.rbegin(), row.rend());
        int score = 0;
        for (int c = 0; c < nums[0].size(); c++) {
            int mx = 0;
            for (int r = 0; r < nums.size(); r++) mx = max(mx, nums[r][c]);
            score += mx;
        }
        return score;
    }
};
