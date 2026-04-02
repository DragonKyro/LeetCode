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
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> times(n);
        for (int i = 0; i < n; i++) times[i] = (dist[i] + speed[i] - 1) / speed[i];
        sort(times.begin(), times.end());
        for (int i = 0; i < n; i++) {
            if (times[i] <= i) return i;
        }
        return n;
    }
};
