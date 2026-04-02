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
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (dist.size() - 1 >= hour) return -1;
        int lo = 1, hi = 1e7;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            double total = 0;
            for (int i = 0; i < (int)dist.size() - 1; i++) total += ceil((double)dist[i] / mid);
            total += (double)dist.back() / mid;
            if (total <= hour) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
