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
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        count[0] = 1;
        int prefix = 0, result = 0;
        for (int num : nums) {
            prefix = ((prefix + num) % k + k) % k;
            result += count[prefix]++;
        }
        return result;
    }
};
