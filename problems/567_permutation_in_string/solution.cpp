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
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> count(26, 0);
        for (int i = 0; i < (int)s1.size(); i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        auto allZero = [&]() { for (int c : count) if (c) return false; return true; };
        if (allZero()) return true;
        for (int i = s1.size(); i < (int)s2.size(); i++) {
            count[s2[i] - 'a']--;
            count[s2[i - s1.size()] - 'a']++;
            if (allZero()) return true;
        }
        return false;
    }
};
