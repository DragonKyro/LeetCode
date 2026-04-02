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
    int minSteps(string s, string t) {
        int cs[26] = {}, ct[26] = {};
        for (char c : s) cs[c-'a']++;
        for (char c : t) ct[c-'a']++;
        int res = 0;
        for (int i = 0; i < 26; i++) res += max(0, cs[i] - ct[i]);
        return res;
    }
};
