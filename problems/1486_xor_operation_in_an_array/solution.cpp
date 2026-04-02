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
    int xorOperation(int n, int start) {
        int res = 0;
        for (int i = 0; i < n; i++) res ^= start + 2 * i;
        return res;
    }
};
