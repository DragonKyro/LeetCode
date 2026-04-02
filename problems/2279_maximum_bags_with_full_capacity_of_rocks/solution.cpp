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
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> remaining(n);
        for (int i = 0; i < n; i++) remaining[i] = capacity[i] - rocks[i];
        sort(remaining.begin(), remaining.end());
        int count = 0;
        for (int r : remaining) {
            if (additionalRocks >= r) { additionalRocks -= r; count++; }
            else break;
        }
        return count;
    }
};
