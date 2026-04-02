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
    int minCostClimbingStairs(vector<int>& cost) {
        int a = 0, b = 0;
        for (int i = 2; i <= (int)cost.size(); i++) {
            int temp = min(b + cost[i-1], a + cost[i-2]);
            a = b;
            b = temp;
        }
        return b;
    }
};
