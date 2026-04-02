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
    bool areAlmostEqual(string s1, string s2) {
        vector<int> diffs;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) diffs.push_back(i);
        }
        if (diffs.size() == 0) return true;
        if (diffs.size() != 2) return false;
        return s1[diffs[0]] == s2[diffs[1]] && s1[diffs[1]] == s2[diffs[0]];
    }
};
