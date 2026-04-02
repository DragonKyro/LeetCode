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
    int minimumMoves(string s) {
        int moves = 0, i = 0;
        while (i < (int)s.size()) {
            if (s[i] == 'X') {
                moves++;
                i += 3;
            } else {
                i++;
            }
        }
        return moves;
    }
};
