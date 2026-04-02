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
    long long findTheArrayConcVal(vector<int>& nums) {
        long long val = 0;
        int i = 0, j = nums.size() - 1;
        while (i < j) { val += stoll(to_string(nums[i]) + to_string(nums[j])); i++; j--; }
        if (i == j) val += nums[i];
        return val;
    }
};
