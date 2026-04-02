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
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) if (canPart(to_string(i*i), 0, i)) ans += i*i;
        return ans;
    }
    bool canPart(string s, int idx, int target) {
        if (idx == s.size()) return target == 0;
        int val = 0;
        for (int i = idx; i < s.size(); i++) {
            val = val * 10 + (s[i]-'0');
            if (val <= target && canPart(s, i+1, target-val)) return true;
        }
        return false;
    }
};
