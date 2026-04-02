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
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0, maxSoFar = 0;
        for (int i = 0; i < (int)arr.size(); i++) {
            maxSoFar = max(maxSoFar, arr[i]);
            if (maxSoFar == i) chunks++;
        }
        return chunks;
    }
};
