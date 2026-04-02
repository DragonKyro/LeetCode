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
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> b(banned.begin(), banned.end());
        int count = 0, total = 0;
        for (int i = 1; i <= n; i++) {
            if (!b.count(i)) { if (total+i > maxSum) break; total+=i; count++; }
        }
        return count;
    }
};
