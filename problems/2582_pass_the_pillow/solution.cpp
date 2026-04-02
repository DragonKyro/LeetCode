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
    int passThePillow(int n, int time) {
        int cycle = 2 * (n - 1);
        time %= cycle;
        return time < n ? time + 1 : 2 * n - 1 - time;
    }
};
