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
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto& a, auto& b) { return a[1] > b[1]; });
        int units = 0;
        for (auto& box : boxTypes) {
            int take = min(box[0], truckSize);
            units += take * box[1];
            truckSize -= take;
            if (truckSize == 0) break;
        }
        return units;
    }
};
