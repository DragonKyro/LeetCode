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
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> result;
        int n = arr.size();
        for (int size = n; size > 1; size--) {
            int maxIdx = max_element(arr.begin(), arr.begin() + size) - arr.begin();
            if (maxIdx == size - 1) continue;
            if (maxIdx != 0) { result.push_back(maxIdx + 1); reverse(arr.begin(), arr.begin() + maxIdx + 1); }
            result.push_back(size); reverse(arr.begin(), arr.begin() + size);
        }
        return result;
    }
};
