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
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size();
        for (int i = 0; i <= n - m * k; i++) {
            bool found = true;
            for (int j = 0; j < m * k; j++) {
                if (arr[i + j] != arr[i + j % m]) { found = false; break; }
            }
            if (found) return true;
        }
        return false;
    }
};
