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
    string sortString(string s) {
        int count[26] = {};
        for (char c : s) count[c-'a']++;
        string res;
        while ((int)res.size() < (int)s.size()) {
            for (int i = 0; i < 26; i++) if (count[i] > 0) { res += (char)(i+'a'); count[i]--; }
            for (int i = 25; i >= 0; i--) if (count[i] > 0) { res += (char)(i+'a'); count[i]--; }
        }
        return res;
    }
};
