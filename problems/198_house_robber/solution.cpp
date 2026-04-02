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
    int rob(vector<int>& nums) {
        int prev = 0, curr = 0;
        for (int num : nums) {
            int tmp = curr;
            curr = max(curr, prev + num);
            prev = tmp;
        }
        return curr;
    }
};
