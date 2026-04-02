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
    int rectangleArea(vector<vector<int>>& rectangles) {
        long MOD = 1e9 + 7;
        vector<array<int,4>> events;
        for (auto& r : rectangles) {
            events.push_back({r[0], 0, r[1], r[3]});
            events.push_back({r[2], 1, r[1], r[3]});
        }
        sort(events.begin(), events.end());
        vector<pair<int,int>> active;
        long result = 0;
        int prevX = events[0][0];
        for (auto& e : events) {
            long yLen = 0; int cur = -1;
            auto sorted = active;
            sort(sorted.begin(), sorted.end());
            for (auto& [y1, y2] : sorted) {
                int lo = max(y1, cur);
                if (lo < y2) yLen += y2 - lo;
                cur = max(cur, y2);
            }
            result = (result + yLen * (e[0] - prevX)) % MOD;
            if (e[1] == 0) active.push_back({e[2], e[3]});
            else active.erase(find(active.begin(), active.end(), make_pair(e[2], e[3])));
            prevX = e[0];
        }
        return result;
    }
};
