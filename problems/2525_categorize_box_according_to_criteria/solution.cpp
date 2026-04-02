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
    string categorizeBox(int l, int w, int h, int mass) {
        bool bulky = l>=10000||w>=10000||h>=10000||(long long)l*w*h>=1000000000LL;
        bool heavy = mass >= 100;
        if (bulky&&heavy) return "Both";
        if (bulky) return "Bulky";
        if (heavy) return "Heavy";
        return "Neither";
    }
};
