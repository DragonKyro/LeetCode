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
    bool queryString(string s, int n) {
        for (int i = 1; i <= n; i++) {
            string bin;
            for (int x = i; x > 0; x >>= 1) bin = char('0' + (x & 1)) + bin;
            if (s.find(bin) == string::npos) return false;
        }
        return true;
    }
};
