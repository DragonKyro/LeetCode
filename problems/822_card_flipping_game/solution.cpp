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
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> same;
        for (int i = 0; i < fronts.size(); i++)
            if (fronts[i] == backs[i]) same.insert(fronts[i]);
        int res = INT_MAX;
        for (int x : fronts) if (!same.count(x)) res = min(res, x);
        for (int x : backs) if (!same.count(x)) res = min(res, x);
        return res == INT_MAX ? 0 : res;
    }
};
