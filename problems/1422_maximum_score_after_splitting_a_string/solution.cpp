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
    int maxScore(string s) {
        int ones = count(s.begin(), s.end(), '1');
        int zeros = 0, best = 0;
        for (int i = 0; i < (int)s.size() - 1; i++) {
            if (s[i] == '0') zeros++;
            else ones--;
            best = max(best, zeros + ones);
        }
        return best;
    }
};
