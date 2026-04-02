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
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size(), inc = 1, dec = 1, result = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) { inc = dec + 1; dec = 1; }
            else if (arr[i] < arr[i - 1]) { dec = inc + 1; inc = 1; }
            else { inc = 1; dec = 1; }
            result = max(result, max(inc, dec));
        }
        return result;
    }
};
