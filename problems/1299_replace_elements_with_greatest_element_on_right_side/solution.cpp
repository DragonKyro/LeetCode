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
    vector<int> replaceElements(vector<int>& arr) {
        int maxRight = -1;
        for (int i = arr.size() - 1; i >= 0; i--) {
            int newMax = max(maxRight, arr[i]);
            arr[i] = maxRight;
            maxRight = newMax;
        }
        return arr;
    }
};
