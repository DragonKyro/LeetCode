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
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size(), res = 0, l = 0, cnt[2] = {};
        for (int r = 0; r < n; r++) {
            cnt[s[r]-'0']++;
            while (cnt[0] > k && cnt[1] > k) cnt[s[l++]-'0']--;
            res += r - l + 1;
        }
        return res;
    }
};
