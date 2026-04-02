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
    long long fuel = 0;
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> graph(n);
        for (auto& r : roads) { graph[r[0]].push_back(r[1]); graph[r[1]].push_back(r[0]); }
        dfs(0, -1, graph, seats);
        return fuel;
    }
    long long dfs(int node, int parent, vector<vector<int>>& graph, int seats) {
        long long people = 1;
        for (int nb : graph[node]) {
            if (nb != parent) people += dfs(nb, node, graph, seats);
        }
        if (node != 0) fuel += (people + seats - 1) / seats;
        return people;
    }
};
