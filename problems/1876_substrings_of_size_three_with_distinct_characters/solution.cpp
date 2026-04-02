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
    int countGoodSubstrings(string s) {
        int count = 0;
        for (int i = 0; i + 2 < s.size(); i++) {
            if (s[i] != s[i+1] && s[i] != s[i+2] && s[i+1] != s[i+2]) count++;
        }
        return count;
    }
};
