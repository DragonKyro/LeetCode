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
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> losses;
        for (auto& m : matches) {
            if (!losses.count(m[0])) losses[m[0]] = 0;
            losses[m[1]]++;
        }
        vector<int> noLoss, oneLoss;
        for (auto& [p, l] : losses) {
            if (l == 0) noLoss.push_back(p);
            else if (l == 1) oneLoss.push_back(p);
        }
        return {noLoss, oneLoss};
    }
};
