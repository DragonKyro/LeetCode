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
    int minFlipsMonoIncr(string s) {
        int ones = 0, flips = 0;
        for (char c : s) {
            if (c == '1') ones++;
            else flips = min(flips + 1, ones);
        }
        return flips;
    }
};
