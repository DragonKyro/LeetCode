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
    int longestString(int x, int y, int z) {
        return (min(x, y) * 2 + (x != y ? 1 : 0) + z) * 2;
    }
};
