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
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int bestD = divisors[0], bestCnt = -1;
        for (int d : divisors) {
            int cnt = 0; for (int n : nums) if (n % d == 0) cnt++;
            if (cnt > bestCnt || (cnt == bestCnt && d < bestD)) { bestD = d; bestCnt = cnt; }
        }
        return bestD;
    }
};
