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
    int minStartValue(vector<int>& nums) {
        int minPrefix = 0, prefix = 0;
        for (int n : nums) {
            prefix += n;
            minPrefix = min(minPrefix, prefix);
        }
        return 1 - minPrefix;
    }
};
