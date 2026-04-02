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
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length(), lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) lo = mid + 1;
            else hi = mid;
        }
        int peak = lo;
        lo = 0; hi = peak;
        while (lo <= hi) {
            int mid = (lo + hi) / 2, val = mountainArr.get(mid);
            if (val == target) return mid;
            else if (val < target) lo = mid + 1;
            else hi = mid - 1;
        }
        lo = peak; hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2, val = mountainArr.get(mid);
            if (val == target) return mid;
            else if (val > target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }
};
