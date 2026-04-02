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
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity) return false;
        if (jug1Capacity == 0 || jug2Capacity == 0)
            return targetCapacity == 0 || jug1Capacity + jug2Capacity == targetCapacity;
        return targetCapacity % __gcd(jug1Capacity, jug2Capacity) == 0;
    }
};
