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
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double lo = 0, hi = 1;
        while (lo < hi) {
            double mid = (lo + hi) / 2;
            int count = 0, p = 0, q = 1, j = 1;
            for (int i = 0; i < n; i++) {
                while (j < n && (double)arr[i] / arr[j] > mid) j++;
                count += n - j;
                if (j < n && (long long)arr[i] * q > (long long)p * arr[j]) {
                    p = arr[i]; q = arr[j];
                }
            }
            if (count == k) return {p, q};
            else if (count < k) lo = mid;
            else hi = mid;
        }
        return {};
    }
};
