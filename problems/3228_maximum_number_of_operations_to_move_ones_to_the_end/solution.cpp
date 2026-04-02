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
    int maxOperations(string s) {
        int res = 0, ones = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') ones++;
            else if (i > 0 && s[i-1] == '1') res += ones;
        }
        return res;
    }
};
