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
    string longestDupSubstring(string s) {
        int lo = 0, hi = s.size() - 1;
        string result;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            string dup = check(s, mid);
            if (!dup.empty()) { result = dup; lo = mid + 1; }
            else hi = mid - 1;
        }
        return result;
    }
    string check(string& s, int len) {
        if (len == 0) return "";
        long long MOD = (1LL << 31) - 1, base = 26, h = 0, power = 1;
        for (int i = 0; i < len; i++) power = power * base % MOD;
        unordered_map<long long, vector<int>> seen;
        for (int i = 0; i < (int)s.size(); i++) {
            h = (h * base + s[i] - 'a') % MOD;
            if (i >= len) h = (h - (s[i-len] - 'a') * power % MOD + MOD) % MOD;
            if (i >= len - 1) {
                for (int j : seen[h])
                    if (s.substr(j, len) == s.substr(i-len+1, len))
                        return s.substr(j, len);
                seen[h].push_back(i - len + 1);
            }
        }
        return "";
    }
};
