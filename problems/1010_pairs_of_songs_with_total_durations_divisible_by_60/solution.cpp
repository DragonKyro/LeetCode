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
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> count(60, 0);
        int ans = 0;
        for (int t : time) {
            int r = t % 60;
            ans += count[(60 - r) % 60];
            count[r]++;
        }
        return ans;
    }
};
