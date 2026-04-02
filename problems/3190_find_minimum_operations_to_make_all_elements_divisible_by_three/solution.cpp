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
    int minimumOperations(vector<int>& nums) {
        int res = 0;
        for (int x : nums) if (x % 3 != 0) res++;
        return res;
    }
};
