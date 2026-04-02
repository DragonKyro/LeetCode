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
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) nums[i] += nums[i-1];
        vector<int> result;
        for (int q : queries) result.push_back(upper_bound(nums.begin(), nums.end(), q) - nums.begin());
        return result;
    }
};
