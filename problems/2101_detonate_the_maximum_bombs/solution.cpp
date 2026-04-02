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
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    long long dx = bombs[i][0] - bombs[j][0];
                    long long dy = bombs[i][1] - bombs[j][1];
                    if (dx * dx + dy * dy <= (long long)bombs[i][2] * bombs[i][2])
                        graph[i].push_back(j);
                }
            }
        }
        int maxCount = 0;
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            queue<int> q;
            q.push(i); visited[i] = true;
            int count = 0;
            while (!q.empty()) {
                int node = q.front(); q.pop(); count++;
                for (int nei : graph[node]) {
                    if (!visited[nei]) { visited[nei] = true; q.push(nei); }
                }
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};
