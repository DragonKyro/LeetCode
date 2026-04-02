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
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> s = {a, b, c};
        sort(s.begin(), s.end());
        if (s[2] - s[0] == 2) return {0, 0};
        int minMoves = (s[1] - s[0] <= 2 || s[2] - s[1] <= 2) ? 1 : 2;
        int maxMoves = s[2] - s[0] - 2;
        return {minMoves, maxMoves};
    }
};
