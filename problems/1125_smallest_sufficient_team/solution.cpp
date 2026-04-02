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
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        unordered_map<string, int> skillIdx;
        for (int i = 0; i < n; i++) skillIdx[req_skills[i]] = i;
        unordered_map<int, vector<int>> dp;
        dp[0] = {};
        for (int i = 0; i < people.size(); i++) {
            int mask = 0;
            for (auto& skill : people[i]) {
                if (skillIdx.count(skill)) mask |= 1 << skillIdx[skill];
            }
            vector<pair<int, vector<int>>> entries(dp.begin(), dp.end());
            for (auto& [state, team] : entries) {
                int newState = state | mask;
                if (!dp.count(newState) || dp[newState].size() > team.size() + 1) {
                    dp[newState] = team;
                    dp[newState].push_back(i);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};
