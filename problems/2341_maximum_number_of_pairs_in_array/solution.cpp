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
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int n : nums) count[n]++;
        int pairs = 0;
        for (auto& [k, v] : count) pairs += v / 2;
        return {pairs, (int)nums.size() - pairs * 2};
    }
};
