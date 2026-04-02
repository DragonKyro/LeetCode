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
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int result = 0, j = 0;
        for (int house : houses) {
            while (j < heaters.size() - 1 && abs(heaters[j + 1] - house) <= abs(heaters[j] - house)) j++;
            result = max(result, abs(heaters[j] - house));
        }
        return result;
    }
};
