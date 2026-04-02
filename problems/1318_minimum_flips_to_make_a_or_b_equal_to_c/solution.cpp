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
    int minFlips(int a, int b, int c) {
        int flips = 0;
        for (int i = 0; i < 32; i++) {
            int ba = (a>>i)&1, bb = (b>>i)&1, bc = (c>>i)&1;
            if (bc == 1) { if (!ba && !bb) flips++; }
            else flips += ba + bb;
        }
        return flips;
    }
};
