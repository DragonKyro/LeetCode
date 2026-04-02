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
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int total = 0;
        for (int i = 0; i < (int)cost.size(); i++) {
            if (i % 3 != 2) total += cost[i];
        }
        return total;
    }
};
