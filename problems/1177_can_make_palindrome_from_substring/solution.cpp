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
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] ^ (1 << (s[i] - 'a'));
        }
        vector<bool> result;
        for (auto& q : queries) {
            int diff = prefix[q[1] + 1] ^ prefix[q[0]];
            int oddCount = __builtin_popcount(diff);
            result.push_back(oddCount / 2 <= q[2]);
        }
        return result;
    }
};
