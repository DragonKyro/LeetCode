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
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        unordered_map<int, vector<int>> stopToRoutes;
        for (int i = 0; i < routes.size(); i++)
            for (int stop : routes[i]) stopToRoutes[stop].push_back(i);
        unordered_set<int> visitedStops = {source};
        unordered_set<int> visitedRoutes;
        queue<int> q;
        q.push(source);
        int buses = 0;
        while (!q.empty()) {
            buses++;
            int sz = q.size();
            while (sz--) {
                int stop = q.front(); q.pop();
                for (int route : stopToRoutes[stop]) {
                    if (visitedRoutes.count(route)) continue;
                    visitedRoutes.insert(route);
                    for (int next : routes[route]) {
                        if (next == target) return buses;
                        if (!visitedStops.count(next)) { visitedStops.insert(next); q.push(next); }
                    }
                }
            }
        }
        return -1;
    }
};
