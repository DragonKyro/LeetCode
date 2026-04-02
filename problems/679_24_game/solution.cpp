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
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }
    bool solve(vector<double>& nums) {
        if (nums.size() == 1) return abs(nums[0] - 24) < 1e-6;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) continue;
                vector<double> rest;
                for (int k = 0; k < nums.size(); k++) if (k != i && k != j) rest.push_back(nums[k]);
                double a = nums[i], b = nums[j];
                for (double val : {a+b, a-b, a*b}) {
                    rest.push_back(val);
                    if (solve(rest)) return true;
                    rest.pop_back();
                }
                if (abs(b) > 1e-6) {
                    rest.push_back(a / b);
                    if (solve(rest)) return true;
                    rest.pop_back();
                }
            }
        }
        return false;
    }
};
