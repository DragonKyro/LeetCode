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
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;
        for (int x : arr1) {
            bool valid = true;
            for (int y : arr2) if (abs(x - y) <= d) { valid = false; break; }
            if (valid) count++;
        }
        return count;
    }
};
