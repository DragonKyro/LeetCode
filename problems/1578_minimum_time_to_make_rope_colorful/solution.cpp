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
    int minCost(string colors, vector<int>& neededTime) {
        int total = 0, i = 0;
        while (i < (int)colors.size()) {
            int j = i, groupSum = 0, groupMax = 0;
            while (j < (int)colors.size() && colors[j] == colors[i]) {
                groupSum += neededTime[j];
                groupMax = max(groupMax, neededTime[j]);
                j++;
            }
            total += groupSum - groupMax;
            i = j;
        }
        return total;
    }
};
