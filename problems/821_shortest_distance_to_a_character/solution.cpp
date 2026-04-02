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
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> res(n);
        int pos = -n;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) pos = i;
            res[i] = i - pos;
        }
        pos = 2 * n;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) pos = i;
            res[i] = min(res[i], pos - i);
        }
        return res;
    }
};
