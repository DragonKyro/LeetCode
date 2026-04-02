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
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> g(n);
        for (int i = 0; i < n-1; i++) g[i].push_back(i+1);
        vector<int> res;
        for (auto& q : queries) {
            g[q[0]].push_back(q[1]);
            vector<int> dist(n, -1); dist[0] = 0;
            queue<int> qu; qu.push(0);
            while (!qu.empty()) {
                int u = qu.front(); qu.pop();
                for (int v : g[u]) if (dist[v]==-1) { dist[v]=dist[u]+1; qu.push(v); }
            }
            res.push_back(dist[n-1]);
        }
        return res;
    }
};
