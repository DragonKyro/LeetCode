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
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> sources;
        for (auto& p : paths) sources.insert(p[0]);
        for (auto& p : paths) {
            if (!sources.count(p[1])) return p[1];
        }
        return "";
    }
};
