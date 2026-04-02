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
    char repeatedCharacter(string s) {
        unordered_set<char> seen;
        for (char c : s) {
            if (seen.count(c)) return c;
            seen.insert(c);
        }
        return ' ';
    }
};
