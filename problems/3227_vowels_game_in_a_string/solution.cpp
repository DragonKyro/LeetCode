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
    bool doesAliceWin(string s) {
        for (char c : s) if (string("aeiou").find(c) != string::npos) return true;
        return false;
    }
};
