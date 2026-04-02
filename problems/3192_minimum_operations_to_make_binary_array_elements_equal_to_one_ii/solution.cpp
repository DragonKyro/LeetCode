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
    int minOperations(vector<int>& nums) {
        int ops = 0, flip = 0;
        for (int x : nums) {
            if ((x ^ (flip & 1)) == 0) { ops++; flip++; }
        }
        return ops;
    }
};
