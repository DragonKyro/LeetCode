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
    int largestAltitude(vector<int>& gain) {
        int altitude = 0, maxAlt = 0;
        for (int g : gain) {
            altitude += g;
            maxAlt = max(maxAlt, altitude);
        }
        return maxAlt;
    }
};
