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
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for (int x : nums) {
            if (x == 0) return 0;
            if (x < 0) sign *= -1;
        }
        return sign;
    }
};
