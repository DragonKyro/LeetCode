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
    bool hasAlternatingBits(int n) {
        long x = n ^ (n >> 1);
        return (x & (x + 1)) == 0;
    }
};
