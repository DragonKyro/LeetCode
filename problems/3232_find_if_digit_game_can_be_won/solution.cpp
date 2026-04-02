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
    bool canAliceWin(vector<int>& nums) {
        int s = 0, d = 0;
        for (int x : nums) { if (x < 10) s += x; else d += x; }
        return s != d;
    }
};
