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
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        auto getDist = [&](int start) {
            vector<int> dist(n, -1);
            int d = 0;
            while (start != -1 && dist[start] == -1) {
                dist[start] = d++;
                start = edges[start];
            }
            return dist;
        };
        auto dist1 = getDist(node1), dist2 = getDist(node2);
        int result = -1, minDist = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (dist1[i] >= 0 && dist2[i] >= 0) {
                int d = max(dist1[i], dist2[i]);
                if (d < minDist) { minDist = d; result = i; }
            }
        }
        return result;
    }
};
