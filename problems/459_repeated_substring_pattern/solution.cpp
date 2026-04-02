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
    bool repeatedSubstringPattern(string s) {
        string doubled = s + s;
        return doubled.substr(1, doubled.size() - 2).find(s) != string::npos;
    }
};
