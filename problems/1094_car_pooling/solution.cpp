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
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int changes[1001] = {};
        for (auto& t : trips) { changes[t[1]] += t[0]; changes[t[2]] -= t[0]; }
        int current = 0;
        for (int c : changes) {
            current += c;
            if (current > capacity) return false;
        }
        return true;
    }
};
