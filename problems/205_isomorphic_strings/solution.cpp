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
    bool isIsomorphic(string s, string t) {
        int mapS[256] = {}, mapT[256] = {};
        for (int i = 0; i < s.size(); i++) {
            if (mapS[(unsigned char)s[i]] != mapT[(unsigned char)t[i]]) return false;
            mapS[(unsigned char)s[i]] = i + 1;
            mapT[(unsigned char)t[i]] = i + 1;
        }
        return true;
    }
};
