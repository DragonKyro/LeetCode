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
    int distanceTraveled(int mainTank, int additionalTank) {
        int dist = 0;
        while (mainTank >= 5) { mainTank -= 5; dist += 50; if (additionalTank > 0) { mainTank++; additionalTank--; } }
        return dist + mainTank * 10;
    }
};
