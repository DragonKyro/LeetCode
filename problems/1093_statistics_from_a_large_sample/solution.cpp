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
    vector<double> sampleStats(vector<int>& count) {
        int mn = -1, mx = -1, mode = 0;
        long long total = 0, n = 0;
        int maxCount = 0;
        for (int i = 0; i < 256; i++) {
            if (count[i] > 0) {
                if (mn == -1) mn = i;
                mx = i;
                total += (long long)i * count[i];
                n += count[i];
                if (count[i] > maxCount) { maxCount = count[i]; mode = i; }
            }
        }
        double mean = (double)total / n;
        long long mid1 = (n - 1) / 2, mid2 = n / 2;
        int m1 = 0, m2 = 0;
        long long cumul = 0;
        for (int i = 0; i < 256; i++) {
            cumul += count[i];
            if (m1 == 0 && cumul > mid1) m1 = i;
            if (m2 == 0 && cumul > mid2) m2 = i;
        }
        double median = (m1 + m2) / 2.0;
        return {(double)mn, (double)mx, mean, median, (double)mode};
    }
};
