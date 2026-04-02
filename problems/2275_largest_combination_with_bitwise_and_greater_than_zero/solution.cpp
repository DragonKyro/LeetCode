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
    int largestCombination(vector<int>& candidates) {
        int result = 0;
        for (int bit = 0; bit < 24; bit++) {
            int count = 0;
            for (int c : candidates) if (c & (1 << bit)) count++;
            result = max(result, count);
        }
        return result;
    }
};
