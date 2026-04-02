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
    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (total % 4 != 0) return false;
        int side = total / 4;
        sort(matchsticks.rbegin(), matchsticks.rend());
        vector<int> sides(4, 0);
        return backtrack(matchsticks, sides, 0, side);
    }
    bool backtrack(vector<int>& m, vector<int>& sides, int idx, int side) {
        if (idx == m.size()) return sides[0] == side && sides[1] == side && sides[2] == side;
        for (int i = 0; i < 4; i++) {
            if (sides[i] + m[idx] <= side) {
                sides[i] += m[idx];
                if (backtrack(m, sides, idx + 1, side)) return true;
                sides[i] -= m[idx];
                if (sides[i] == 0) break;
            }
        }
        return false;
    }
};
