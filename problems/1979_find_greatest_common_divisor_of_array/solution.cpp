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
    int findGCD(vector<int>& nums) {
        return __gcd(*min_element(nums.begin(), nums.end()), *max_element(nums.begin(), nums.end()));
    }
};
