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
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](auto& a, auto& b) { return a[1] < b[1]; });
        int count = 1, end = pairs[0][1];
        for (int i = 1; i < pairs.size(); i++) {
            if (pairs[i][0] > end) {
                count++;
                end = pairs[i][1];
            }
        }
        return count;
    }
};
