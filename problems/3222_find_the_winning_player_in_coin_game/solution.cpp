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
    string losingPlayer(int x, int y) {
        int turns = min(x, y / 4);
        return turns % 2 == 1 ? "Alice" : "Bob";
    }
};
