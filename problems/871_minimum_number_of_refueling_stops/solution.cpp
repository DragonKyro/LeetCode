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
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int fuel = startFuel, stops = 0, prev = 0;
        stations.push_back({target, 0});
        for (auto& s : stations) {
            fuel -= s[0] - prev;
            while (!pq.empty() && fuel < 0) { fuel += pq.top(); pq.pop(); stops++; }
            if (fuel < 0) return -1;
            pq.push(s[1]);
            prev = s[0];
        }
        return stops;
    }
};
