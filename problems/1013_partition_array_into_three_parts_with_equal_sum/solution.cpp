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
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total = accumulate(arr.begin(), arr.end(), 0);
        if (total % 3 != 0) return false;
        int target = total / 3, parts = 0, current = 0;
        for (int a : arr) {
            current += a;
            if (current == target) { parts++; current = 0; }
        }
        return parts >= 3;
    }
};
