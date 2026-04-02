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
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> mp;
        for (auto& log : logs) mp[log[0]].insert(log[1]);
        vector<int> answer(k, 0);
        for (auto& [uid, minutes] : mp) {
            int uam = minutes.size();
            if (uam <= k) answer[uam - 1]++;
        }
        return answer;
    }
};
