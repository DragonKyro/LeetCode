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
    int addRungs(vector<int>& rungs, int dist) {
        int result = 0, prev = 0;
        for (int r : rungs) {
            result += (r - prev - 1) / dist;
            prev = r;
        }
        return result;
    }
};
