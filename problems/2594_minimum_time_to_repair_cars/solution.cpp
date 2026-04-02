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
    long long repairCars(vector<int>& ranks, int cars) {
        long long lo = 1, hi = (long long)*min_element(ranks.begin(),ranks.end()) * cars * cars;
        while (lo < hi) {
            long long mid = (lo+hi)/2, total = 0;
            for (int r : ranks) total += (long long)sqrt((double)mid/r);
            if (total >= cars) hi = mid; else lo = mid+1;
        }
        return lo;
    }
};
