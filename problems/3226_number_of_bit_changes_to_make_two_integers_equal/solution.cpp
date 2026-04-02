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
    int minChanges(int n, int k) {
        if ((n & k) != k) return -1;
        return __builtin_popcount(n ^ k);
    }
};
