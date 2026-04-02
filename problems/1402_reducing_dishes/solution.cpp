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
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.rbegin(), satisfaction.rend());
        int res = 0, prefix = 0;
        for (int s : satisfaction) {
            prefix += s;
            if (prefix <= 0) break;
            res += prefix;
        }
        return res;
    }
};
