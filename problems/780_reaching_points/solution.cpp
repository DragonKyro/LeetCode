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
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx == sx && ty == sy) return true;
            if (tx > ty) {
                if (ty == sy) return (tx - sx) % ty == 0;
                tx %= ty;
            } else {
                if (tx == sx) return (ty - sy) % tx == 0;
                ty %= tx;
            }
        }
        return false;
    }
};
