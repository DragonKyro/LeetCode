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
    string rankTeams(vector<string>& votes) {
        int n = votes[0].size();
        unordered_map<char, vector<int>> count;
        for (char c : votes[0]) count[c] = vector<int>(n, 0);
        for (auto& vote : votes)
            for (int i = 0; i < n; i++) count[vote[i]][i]++;
        string teams = votes[0];
        sort(teams.begin(), teams.end(), [&](char a, char b) {
            return count[a] != count[b] ? count[a] > count[b] : a < b;
        });
        return teams;
    }
};
