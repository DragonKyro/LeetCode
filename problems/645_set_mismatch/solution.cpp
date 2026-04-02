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
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n + 1, 0);
        for (int num : nums) count[num]++;
        int dup = 0, miss = 0;
        for (int i = 1; i <= n; i++) {
            if (count[i] == 2) dup = i;
            if (count[i] == 0) miss = i;
        }
        return {dup, miss};
    }
};
