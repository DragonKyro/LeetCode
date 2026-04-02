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
    int differenceOfSum(vector<int>& nums) {
        int eSum = 0, dSum = 0;
        for (int n : nums) { eSum += n; while (n > 0) { dSum += n%10; n /= 10; } }
        return abs(eSum - dSum);
    }
};
