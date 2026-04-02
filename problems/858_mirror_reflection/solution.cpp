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
    int mirrorReflection(int p, int q) {
        int g = __gcd(p, q);
        p /= g; q /= g;
        if (p % 2 == 0) return 2;
        if (q % 2 == 0) return 0;
        return 1;
    }
};
