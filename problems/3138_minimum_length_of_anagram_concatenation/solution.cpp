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
    int minAnagramLength(string s) {
        int n = s.size();
        for (int k = 1; k <= n; k++) {
            if (n % k) continue;
            vector<int> base(26);
            for (int i = 0; i < k; i++) base[s[i]-'a']++;
            bool ok = true;
            for (int i = k; i < n; i += k) {
                vector<int> cur(26);
                for (int j = i; j < i+k; j++) cur[s[j]-'a']++;
                if (cur != base) { ok = false; break; }
            }
            if (ok) return k;
        }
        return n;
    }
};
