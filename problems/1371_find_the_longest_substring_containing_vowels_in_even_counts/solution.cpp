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
    int findTheLongestSubstring(string s) {
        unordered_map<int,int> first;
        first[0] = -1;
        int state = 0, res = 0;
        string vowels = "aeiou";
        for (int i = 0; i < (int)s.size(); i++) {
            int idx = vowels.find(s[i]);
            if (idx != (int)string::npos) state ^= (1 << idx);
            if (first.count(state)) res = max(res, i - first[state]);
            else first[state] = i;
        }
        return res;
    }
};
