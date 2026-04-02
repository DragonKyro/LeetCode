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
    char findTheDifference(string s, string t) {
        int res = 0;
        for (char c : s) res ^= c;
        for (char c : t) res ^= c;
        return (char)res;
    }
};
