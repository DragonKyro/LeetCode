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
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long area = 0;
        set<pair<int,int>> corners;
        for (auto& r : rectangles) {
            area += (long)(r[2] - r[0]) * (r[3] - r[1]);
            pair<int,int> cs[] = {{r[0],r[1]},{r[0],r[3]},{r[2],r[1]},{r[2],r[3]}};
            for (auto& c : cs) {
                if (corners.count(c)) corners.erase(c);
                else corners.insert(c);
            }
        }
        if (corners.size() != 4) return false;
        auto it = corners.begin();
        int x1 = it->first, y1 = it->second;
        advance(it, 3);
        int x2 = it->first, y2 = it->second;
        return area == (long)(x2 - x1) * (y2 - y1);
    }
};
