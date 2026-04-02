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
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> stack;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && stack.back() > nums[i] && (int)(stack.size() + n - i) > k) {
                stack.pop_back();
            }
            if ((int)stack.size() < k) stack.push_back(nums[i]);
        }
        return stack;
    }
};
