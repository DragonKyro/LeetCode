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
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < heights.size() - 1; i++) {
            int diff = heights[i + 1] - heights[i];
            if (diff <= 0) continue;
            pq.push(diff);
            if ((int)pq.size() > ladders) {
                bricks -= pq.top();
                pq.pop();
            }
            if (bricks < 0) return i;
        }
        return heights.size() - 1;
    }
};
