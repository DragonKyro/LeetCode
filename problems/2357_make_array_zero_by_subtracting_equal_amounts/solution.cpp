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
        set<int> s;
        for (int n : nums) if (n > 0) s.insert(n);
        return s.size();
    }
};
