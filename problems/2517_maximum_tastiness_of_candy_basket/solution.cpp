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
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int lo = 0, hi = price.back() - price[0];
        while (lo < hi) {
            int mid = (lo+hi+1)/2, cnt = 1, prev = price[0];
            for (int p : price) if (p-prev>=mid) { cnt++; prev=p; }
            if (cnt >= k) lo = mid; else hi = mid-1;
        }
        return lo;
    }
};
