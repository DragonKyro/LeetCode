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
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int idx = ruleKey == "type" ? 0 : ruleKey == "color" ? 1 : 2;
        int count = 0;
        for (auto& item : items) {
            if (item[idx] == ruleValue) count++;
        }
        return count;
    }
};
