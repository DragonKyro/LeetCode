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
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        auto dist = [](vector<int>& a, vector<int>& b) {
            return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
        };
        vector<vector<int>> pts = {p1, p2, p3, p4};
        vector<int> dists;
        for (int i = 0; i < 4; i++)
            for (int j = i+1; j < 4; j++)
                dists.push_back(dist(pts[i], pts[j]));
        sort(dists.begin(), dists.end());
        return dists[0] > 0 && dists[0] == dists[3] && dists[4] == dists[5] && dists[4] == 2 * dists[0];
    }
};
