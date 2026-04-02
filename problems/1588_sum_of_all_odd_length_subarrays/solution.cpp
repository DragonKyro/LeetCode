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
    int sumOddLengthSubarrays(vector<int>& arr) {
        int total = 0, n = arr.size();
        for (int i = 0; i < n; i++) {
            total += ((i + 1) * (n - i) + 1) / 2 * arr[i];
        }
        return total;
    }
};
