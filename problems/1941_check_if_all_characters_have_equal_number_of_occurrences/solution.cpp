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
    bool areOccurrencesEqual(string s) {
        int count[26] = {};
        for (char c : s) count[c - 'a']++;
        int target = count[s[0] - 'a'];
        for (int c : count) if (c > 0 && c != target) return false;
        return true;
    }
};
