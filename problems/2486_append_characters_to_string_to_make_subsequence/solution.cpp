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
    int appendCharacters(string s, string t) {
        int j = 0;
        for (int i = 0; i < s.size() && j < t.size(); i++) {
            if (s[i] == t[j]) j++;
        }
        return t.size() - j;
    }
};
