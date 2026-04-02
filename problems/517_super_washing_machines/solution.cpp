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
    int findMinMoves(vector<int>& machines) {
        int total = accumulate(machines.begin(), machines.end(), 0);
        int n = machines.size();
        if (total % n != 0) return -1;
        int avg = total / n, res = 0, runningSum = 0;
        for (int m : machines) {
            int diff = m - avg;
            runningSum += diff;
            res = max({res, abs(runningSum), diff});
        }
        return res;
    }
};
