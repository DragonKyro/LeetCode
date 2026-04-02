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
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
        return mergeSort(prefix, 0, n, lower, upper);
    }
    int mergeSort(vector<long>& p, int lo, int hi, int lower, int upper) {
        if (lo >= hi) return 0;
        int mid = lo + (hi - lo) / 2;
        int count = mergeSort(p, lo, mid, lower, upper) + mergeSort(p, mid + 1, hi, lower, upper);
        int j1 = mid + 1, j2 = mid + 1;
        for (int i = lo; i <= mid; i++) {
            while (j1 <= hi && p[j1] - p[i] < lower) j1++;
            while (j2 <= hi && p[j2] - p[i] <= upper) j2++;
            count += j2 - j1;
        }
        inplace_merge(p.begin() + lo, p.begin() + mid + 1, p.begin() + hi + 1);
        return count;
    }
};
