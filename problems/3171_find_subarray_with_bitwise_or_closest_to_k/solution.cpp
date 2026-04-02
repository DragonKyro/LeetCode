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
    int minimumDifference(vector<int>& nums, int k) {
        int res = INT_MAX;
        unordered_set<int> curr;
        for (int x : nums) {
            unordered_set<int> nxt;
            nxt.insert(x);
            for (int v : curr) nxt.insert(v & x);
            for (int v : nxt) res = min(res, abs(v - k));
            curr = nxt;
        }
        return res;
    }
};
