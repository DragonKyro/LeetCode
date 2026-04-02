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
    bool hasAllCodes(string s, int k) {
        unordered_set<string> seen;
        for (int i = 0; i <= (int)s.size() - k; i++) {
            seen.insert(s.substr(i, k));
        }
        return (int)seen.size() == (1 << k);
    }
};
