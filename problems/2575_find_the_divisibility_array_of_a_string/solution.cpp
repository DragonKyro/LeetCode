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
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
        long long rem = 0;
        for (char c : word) { rem = (rem * 10 + (c-'0')) % m; ans.push_back(rem == 0 ? 1 : 0); }
        return ans;
    }
};
