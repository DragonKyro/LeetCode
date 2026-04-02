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
    int numberOfChild(int n, int k) {
        int cycle = 2 * (n - 1);
        k %= cycle;
        return k < n ? k : cycle - k;
    }
};
