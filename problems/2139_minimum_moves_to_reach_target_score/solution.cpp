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
    int minMoves(int target, int maxDoubles) {
        int moves = 0;
        while (target > 1) {
            if (maxDoubles == 0) { moves += target - 1; break; }
            if (target % 2 == 1) { target--; moves++; }
            else { target /= 2; maxDoubles--; moves++; }
        }
        return moves;
    }
};
