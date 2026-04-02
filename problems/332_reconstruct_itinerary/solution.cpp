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
    map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    vector<string> route;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& t : tickets)
            graph[t[0]].push(t[1]);
        dfs("JFK");
        reverse(route.begin(), route.end());
        return route;
    }
    void dfs(string airport) {
        while (!graph[airport].empty()) {
            string next = graph[airport].top();
            graph[airport].pop();
            dfs(next);
        }
        route.push_back(airport);
    }
};
