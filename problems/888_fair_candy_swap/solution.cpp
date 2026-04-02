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
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sa = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sb = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int diff = (sb - sa) / 2;
        unordered_set<int> bobSet(bobSizes.begin(), bobSizes.end());
        for (int a : aliceSizes) if (bobSet.count(a + diff)) return {a, a + diff};
        return {};
    }
};
