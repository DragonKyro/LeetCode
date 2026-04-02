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
    vector<int> memLeak(int memory1, int memory2) {
        int t = 1;
        while (t <= max(memory1, memory2)) {
            if (memory1 >= memory2) memory1 -= t;
            else memory2 -= t;
            t++;
        }
        return {t, memory1, memory2};
    }
};
