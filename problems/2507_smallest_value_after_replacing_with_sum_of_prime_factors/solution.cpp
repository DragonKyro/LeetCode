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
    int smallestValue(int n) {
        while (true) {
            int s = 0, x = n;
            for (int d = 2; d * d <= x; d++) while (x % d == 0) { s += d; x /= d; }
            if (x > 1) s += x;
            if (s == n) return n;
            n = s;
        }
    }
};
