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
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> vis(n, false);
        int cur = 0, step = 1;
        while (!vis[cur]) { vis[cur] = true; cur = (cur + step * k) % n; step++; }
        vector<int> res;
        for (int i = 0; i < n; i++) if (!vis[i]) res.push_back(i+1);
        return res;
    }
};
