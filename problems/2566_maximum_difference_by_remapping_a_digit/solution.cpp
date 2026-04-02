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
    int minMaxDifference(int num) {
        string s = to_string(num), mx = s;
        for (char c : s) if (c != '9') { for (auto& ch : mx) if (ch == c) ch = '9'; break; }
        string mn = s;
        char f = mn[0];
        for (auto& ch : mn) if (ch == f) ch = '0';
        return stoi(mx) - stoi(mn);
    }
};
