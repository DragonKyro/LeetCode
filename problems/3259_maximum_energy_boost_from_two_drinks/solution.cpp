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
    long long maxEnergyBoost(vector<int>& a, vector<int>& b) {
        int n = a.size();
        long long da = a[0], db = b[0];
        for (int i = 1; i < n; i++) {
            long long na = max(da + a[i], db);
            long long nb = max(db + b[i], da);
            da = na; db = nb;
        }
        return max(da, db);
    }
};
