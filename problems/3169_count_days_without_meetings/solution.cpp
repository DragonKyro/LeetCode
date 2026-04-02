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
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int busy = 0, end = 0;
        for (auto& m : meetings) {
            int s = max(m[0], end + 1);
            if (s <= m[1]) { busy += m[1] - s + 1; end = max(end, m[1]); }
        }
        return days - busy;
    }
};
