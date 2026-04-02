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
    int longestCycle(vector<int>& edges) {
        int n = edges.size(), result = -1, time = 1;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (visited[i] > 0) continue;
            int startTime = time, node = i;
            while (node != -1 && visited[node] == 0) {
                visited[node] = time++;
                node = edges[node];
            }
            if (node != -1 && visited[node] >= startTime)
                result = max(result, time - visited[node]);
        }
        return result;
    }
};
